# Vehicle Reminder System (C++)

### 🧭 Project Overview
This project is a lightweight **vehicle document reminder system** developed in **C++**.  
It helps small companies automatically track and alert vehicle-related expiry dates such as:
- Driver's License Expiry
- Permit Expiry
- Annual Vehicle Inspection Expiry

The program imports data from an Excel (converted to CSV) file, stores it in a database, and automatically checks upcoming deadlines.  
When an expiry date is approaching, it issues reminders **30 days before** and repeats every **10 days** until marked as processed.

---

### ⚙️ Core Features
- Import vehicle information from Excel (CSV format)
- Store and manage data in SQLite database
- Automatic reminder calculation based on current date
- Reminder repeat every 10 days until processed
- Mark as “handled” to stop notifications
- Optional future GUI (Qt)

---

### 🧩 Data Fields
| Field | Description |
|-------|--------------|
| Company Name | Name of the company |
| Vehicle Number | Plate number or vehicle ID |
| Driver License Expiry | Expiry date of the driver’s license |
| Permit Expiry | Expiry date of the operating permit |
| Inspection Expiry | Expiry date of annual inspection |
| Last Reminder | Date of last alert |
| Processed | 0 = Not handled, 1 = Handled |

---

### 🏗️ Planned Project Structure
VehicleReminderSystem/
├── src/ # C++ source files (.cpp, .h)
├── data/ # Excel or CSV input data
├── docs/ # Design notes, requirements, logs
├── build/ # Compiled output (ignored by Git)
├── .gitignore
└── README.md

---

### 🧠 Development Plan
| Phase | Goal | Status |
|-------|------|--------|
| 1 | CSV parsing | ✅ |
| 2 | Date comparison logic | ⏳ |
| 3 | SQLite integration | ⏳ |
| 4 | Reminder scheduling | ⏳ |
| 5 | GUI / Notifications | 🔜 |

---

### 💡 Future Improvements
- Add graphical interface using Qt
- Add email or desktop notifications
- Log history of reminders
- Export monthly reports

---

### 👤 Author
Developed by *Ailurus*  
For internal use in a small company (practice project).  
First version started on macOS in November 2025.
# Vehicle Reminder System
