# lua-parse

Lua Parser written in pure C++

## Overview

`lua-parse` is a project aimed at providing a robust Lua parser implemented in C++. This project leverages the Lua C API to load and execute Lua scripts, and it includes XML handling capabilities for configuration purposes.

## Features

- Load and execute Lua scripts.
- Handle multiple Lua scripts simultaneously.
- XML configuration handling.
- Cross-platform support with Visual Studio project files.

### src Directory

- **lua**: Contains Lua source files.
- **xml**: Contains XML handling source files.
- **CCoreLua.cpp**: Implementation of the core Lua handling class.
- **CCoreLua.h**: Header file for the core Lua handling class.
- **CXmlHandler.cpp**: Implementation of the XML handler class.
- **CXmlHandler.h**: Header file for the XML handler class.
- **main.cpp**: Entry point of the application.
- **main.h**: Header file included in the main application.

### LuaParse.sln

- Visual Studio solution file for building the project.

## Getting Started

### Prerequisites

- Visual Studio 2017 or later.
- Lua development libraries.
- XML parsing libraries.

### Building the Project

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/lua-parse.git
    cd lua-parse
    ```

2. Open the `LuaParse.sln` file in Visual Studio.

3. Build the solution by selecting `Build > Build Solution` from the menu.

### Running the Application

1. After building the project, navigate to the output directory (e.g., `Debug` or `Release`).

2. Run the executable:
    ```sh
    ./LuaParse
    ```

## Usage

### Loading Lua Scripts

To load a Lua script, place your `.lua` files in the `scripts` directory and call the `LoadScript` method from the `CCoreLua` class.

### XML Configuration

The application uses XML files for configuration. Ensure your XML files are correctly formatted and placed in the appropriate directory.

## Contributing

Contributions are welcome! Please fork the repository and submit pull requests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For any inquiries or issues, please open an issue on the GitHub repository or contact the maintainer at your.email@example.com.
