// Copyright 2014 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <cstdio>
#include <memory>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

class Talker : public rclcpp::Node
{
public:
    explicit Talker(const std::string &topic_name) : Node("talker")
    {
        msg_ = std::make_shared<std_msgs::msg::String>();
        msg_->data = "Hello world!";

        auto publish_message = [this]() -> void {
            RCLCPP_INFO(this->get_logger(), "%s", msg_->data.c_str());
            pub_->publish(msg_);
        };

        pub_ = create_publisher<std_msgs::msg::String>(topic_name);
        timer_ = create_wall_timer(100ms, publish_message);
    }

private:
    std::shared_ptr<std_msgs::msg::String> msg_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);

    auto node = std::make_shared<Talker>("hello_world");
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
