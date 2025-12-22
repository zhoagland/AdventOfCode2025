# CMakeList.txt : CMake project for AdventOfCode2025, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (AdventOfCode2025 "AdventOfCode2025.cpp" "AdventOfCode2025.h" "AOC_Day1/AOC_Day1.h" "AOC_Day1/AOC_Day1.cpp" "Utilities/FileParser.h" "Utilities/FileParser.cpp" "AOC_Day2/AOC_Day2.cpp" "Utilities/AOC.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AdventOfCode2025 PROPERTY CXX_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
