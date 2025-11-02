#pragma once
#include <chrono>
#include <string>
#include <print>

// Defines class Vehicle for storing and checking document expiry info.
namespace vrs {

    // A single vehicle and its document expiration data.
    class Vehicle {
        private:
            using date = std::chrono::year_month_day;

            static constexpr std::chrono::months reminder_time {1};
            std::string company_name_;
            date driver_license_expiry_;
            date permit_expiry_;
            date inspection_expiry_;
        public:
            Vehicle(std::string name, date license, date permit, date inspection) : 
            company_name_(name),
            driver_license_expiry_(license),
            permit_expiry_(permit),
            inspection_expiry_(inspection)
            {};

            // Returns true if expires within 30 days.
            bool is_license_due() const noexcept {
                using namespace std::chrono;

                const sys_days today = floor<days>(system_clock::now());
                const sys_days expiry = sys_days{driver_license_expiry_};

                return expiry - today <= days{reminder_time.count() * 30};
            }

            // Returns true if expires within 30 days.
            bool is_permit_due() const noexcept {
                using namespace std::chrono;

                const sys_days today = floor<days>(system_clock::now());
                const sys_days expiry = sys_days{permit_expiry_};
                
                return expiry - today <= days{reminder_time.count() * 30};
            } 

            // Returns true if expires within 30 days.
            bool is_inspection_due() const noexcept {
                using namespace std::chrono;

                const sys_days today = floor<days>(system_clock::now());
                const sys_days expiry = sys_days{inspection_expiry_};
                
                return expiry - today <= days{reminder_time.count() * 30};
            } 
            ~Vehicle() = default;
    };
}