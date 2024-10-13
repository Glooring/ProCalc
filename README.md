# **ProCalc (Qt/C++)**

**ProCalc** is an advanced calculator built in **C++** using **Qt** for the graphical interface and **Boost.Multiprecision** for ensuring precision up to 50 decimal places. The application is designed to handle both basic and advanced mathematical operations, featuring a responsive user interface and smooth handling of errors like division by zero.

---

## **Description**

ProCalc supports a wide range of operations, from basic arithmetic (addition, subtraction, multiplication, division) to advanced features like square roots, exponents, and reciprocals. Its high precision is powered by **Boost.Multiprecision**, allowing for highly accurate calculations. The interface is responsive and adapts to window resizing, ensuring a seamless experience across different devices.

---
## **Demonstration**

Here's a quick demonstration of **ProCalc** in use:

<img src="media/calculator_demo.gif" width="240">

In this GIF, you can see how easy it is to perform both basic arithmetic and advanced operations with the calculator. The interface is designed for smooth, error-free usage.

---

## **Key Features**

- **Basic Operations**: Addition, subtraction, multiplication, and division.
- **Advanced Operations**: Square roots, powers, and reciprocal (1/x) operations.
- **Precision**: Up to 50 decimal places using **Boost.Multiprecision**.
- **Responsive Design**: Fully responsive interface built with **Qt**, adapts to window resizing.
- **Error Handling**: Graceful handling of errors such as division by zero.
- **Custom UI Styling**: Buttons and displays are styled with hover and click effects.

---

## **Project Structure**

The project is structured as follows:

```
ProCalc/
│
├── boost_minimal/                    # Reduced Boost library for high-precision calculations
│   └── boost/                        # Header files for Boost Multiprecision library
│
├── build/                            # Build-related folder containing pre-built files and scripts
│   ├── release/                      # Folder containing the pre-built executable and all dependencies
│   │   ├── ProCalc.exe               # The main executable for regular users
│   │   ├── Qt6Core.dll               # Required Qt Core library
│   │   ├── libgcc_s_seh-1.dll        # MinGW runtime library (GCC exception handling)
│   │   ├── libstdc++-6.dll           # MinGW runtime library (Standard C++ library)
│   │   ├── libwinpthread-1.dll       # MinGW runtime library (POSIX threads support)
│   │   └── [Other necessary files]   # Additional Qt DLLs, libraries, and plugins required to run the app
│   └── deploy-release.bat            # Batch script to bundle release with necessary dependencies (renamed for clarity)
│
├── tools/                            # Tools and utility scripts
│   ├── cleanup_boost.py              # Script to remove unnecessary files from the Boost folder
│   └── cleanup_files.txt             # List of files removed from Boost to reduce dependencies
│
├── CMakeLists.txt                    # CMake build configuration file
├── CMakeLists.txt.user.example       # Example of a user-specific CMake configuration (user settings excluded from version control)
├── LICENSE                           # Project license (MIT License or any other applicable license)
├── README.md                         # Documentation for building, running, and contributing to the project
│
├── customFunctions.h                 # Header file containing custom mathematical functions used in the calculator
├── main.cpp                          # Main entry point of the application
├── mainwindow.cpp                    # Implementation of the main window's logic and functionality
├── mainwindow.h                      # Header file for the main window class and its components
├── mainwindow.ui                     # UI definition for the main window, designed in Qt Designer
├── precisionTypes.h                  # Header file defining custom types used for high-precision calculations
└── utilities.h                       # Utility functions and helpers used across the application


```

---

## **Requirements**

### **For Regular Users**
No additional tools are required. The **release** folder includes all the necessary files to run the application.

### **For Developers**
To build **ProCalc** from source, the following are required:

- **Qt Creator 14.0.1 (Community)**: Download and install from [Qt's official website](https://www.qt.io/download).
- **Qt 6.7.2 (mingw_64)**: The Qt version required for building the graphical user interface.
- **Boost.Multiprecision**: The Boost Multiprecision library is already included in the project under the `boost_minimal/` folder. I have eliminated unnecessary dependencies, but you can find the full Boost library `boost_1_86_0` at [Boost.org](https://www.boost.org/users/download/).
- **CMake**: Used for project configuration and building.
---

## **Installation and Setup**

### **For All Users: (Running the Pre-built Executable)**

1. **Navigate to the Release Folder**:
   - Open the **release** folder included in the project repository.

2. **Run the Application**:
   - Double-click the `ProCalc.exe` file located in the **release** folder.

### **For Developers (Building from Source)**

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Glooring/ProCalc.git
   cd ProCalc
   ```

2. **Open the Project** in **Qt Creator**:
   - **Using Qt Creator**: 
     - Open **Qt Creator**.
     - In the **Welcome** window, click **Open Project**, and select the `CMakeLists.txt` file located in the root of the project folder (`ProCalc/`).
     - Qt Creator will use the `CMakeLists.txt` to configure the project structure.
     - By default, the build paths for **Debug** and **Release** are configured from `CMakeLists.txt.user.example`. However, you will need to manually adjust these paths within **Qt Creator**:
       1. Navigate to the **Projects** window in Qt Creator.
       2. Under **Build Settings** for both **Debug** and **Release**, update the **Build directory** path to match your local environment if necessary.
     - Ensure the appropriate build configuration (Debug/Release) is selected before building.

3. **Run the Application**:
   - After building the project in either **Release** or **Debug** mode, run the generated executable from the build directory.

---

This version of the project is pre-packaged with all necessary dependencies (Qt DLLs and MinGW runtime files), so it can be run directly without any additional installations.

---

### **Boost Library Cleanup**

To streamline the **Boost** library for use in **ProCalc**, unnecessary dependencies were manually removed from the original `boost_1_86_0` folder. The resulting reduced version has been renamed to `boost_minimal/`. This reduced Boost library was optimized to retain only the essential files needed for the **Multiprecision** library, reducing its size from **745 MB** to just **30 MB**.

### **Scripts for Boost Cleanup**

1. **cleanup_boost.py**:
   This script uses the list of files in `cleanup_files.txt` to automate the removal of unnecessary files from the Boost folder. This ensures that the Boost folder is slimmed down and suitable for the project, reducing the footprint for the **ProCalc** application.

   - **Usage**:
     ```bash
     python tools/cleanup_boost.py <boost_folder> <cleanup_files.txt>
     ```

   - After the files listed in `cleanup_files.txt` are removed, it also removes any empty directories, ensuring the folder is cleaned thoroughly.

2. **cleanup_files.txt**:
   This file contains the list of paths that were removed during the manual cleaning of the Boost library. It is used by `cleanup_boost.py` to automate the cleaning process.

---

## **Packaging the Release**

The **deploy-release.bat** script is provided to ensure that developers can bundle the application with all the necessary dependencies when creating their own release.

### **Using the Batch File to Include Dependencies**

1. **Run the Batch File**:
   After building the project in **Release** mode, run the `release-include-dependencies.bat` script.

2. **Input Paths**:
   - Enter the full path to the `ProCalc.exe` file (e.g., `C:\Projects\ProCalc\build\Release\ProCalc.exe`).
   - Enter the full path to your **Qt installation’s mingw_64 folder** (e.g., `C:\Qt\6.7.2\mingw_64`).

3. **What the Script Does**:
   - Copies the necessary **Qt DLLs** and **MinGW runtime files** to the release directory.
   - Ensures that the release is ready to be distributed and run on systems without Qt installed.

---

## **Technologies Used**

- **Qt 6.7.2**: Used to build the graphical user interface (GUI).
- **C++17**: For core logic and calculations.
- **Boost.Multiprecision**: Ensures high-precision calculations.
- **CMake**: Used for project configuration and building.
- **MinGW (mingw_64)**: Compiler and runtime environment for building the project on Windows.

---

## **License**

This project is licensed under the MIT License. See the `LICENSE` file for more details.

---

## **Acknowledgments**

Special thanks to the developers of **Qt**, **Boost**, and the open-source community for providing the tools and libraries that power this project.

---

### **Future Improvements**

- **Additional Functions**: Plan to integrate more advanced mathematical functions, such as logarithms and trigonometric functions.
- **Theming Support**: Allow customization of the UI with different themes.
- **Performance Enhancements**: Improve performance for handling large calculations and complex operations.
