cmake_minimum_required(VERSION 3.16)
project(LearnModernCpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

# 递归拿到所有 .cc/.cpp，使用相对路径方便生成唯一 target 名
file(GLOB_RECURSE SOURCES RELATIVE "${CMAKE_SOURCE_DIR}" "*.cc" "*.cpp")

foreach(src IN LISTS SOURCES)
  # 用相对路径生成唯一合法的目标名：把 / 和 . 都替换掉
  string(REPLACE "/" "_" tgt "${src}")
  string(REPLACE "\\" "_" tgt "${tgt}")
  string(REPLACE "." "_" tgt "${tgt}")
  string(REGEX REPLACE "[^A-Za-z0-9_]" "_" tgt "${tgt}")

  add_executable("${tgt}" "${src}")

  # 运行时工作目录设为仓库根，便于读相对路径文件
  set_property(TARGET "${tgt}" PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
endforeach()
