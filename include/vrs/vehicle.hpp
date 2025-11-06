#pragma once
#include <chrono>
#include <string>

// Defines class Vehicle for storing and checking document expiry info.
namespace vrs {

    // A single vehicle and its document expiration data.
    class Vehicle {
        private:
            using date = std::chrono::year_month_day;

            static constexpr std::chrono::days reminder_time {30};

            std::string company_name_;
            date driver_license_expiry_;
            date permit_expiry_;
            date inspection_expiry_;

            //Returns true if dues within 30 days or has expired.
            static bool is_due_soon(const date &expiry_date) noexcept {
                using namespace std::chrono;

                const auto today = floor<days>(system_clock::now());
                const auto &expiry = sys_days(expiry_date);

                return (expiry - today <= reminder_time);
            };

        public:
            explicit Vehicle(std::string name, date license, date permit, date inspection) : 
            company_name_(name),
            driver_license_expiry_(license),
            permit_expiry_(permit),
            inspection_expiry_(inspection)
            {};

            // Returns true if expires within 30 days.
            bool is_license_due() const noexcept {
                return is_due_soon(driver_license_expiry_);
            }
            // Returns true if expires within 30 days.
            bool is_permit_due() const noexcept {
               return is_due_soon(permit_expiry_);
            } 
            // Returns true if expires within 30 days.
            bool is_inspection_due() const noexcept {
               return is_due_soon(inspection_expiry_);
            } 
            ~Vehicle() = default;
    };
}