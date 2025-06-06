# Copyright (c) 2019 LG Electronics, Inc.
# Copyright (C) 2024 Advanced Micro Devices, Inc.  All rights reserved.

ROS_BUILDTOOL_DEPENDS += " \
    rosidl-parser-native \
    rosidl-adapter-native \
    rosidl-typesupport-fastrtps-cpp-native \
    rosidl-typesupport-fastrtps-c-native \
    python3-numpy-native \
    python3-lark-parser-native \
"

# Without the target rosidl-typesupport-{c,cpp}, ament finds the native packages and then fails to link (error: incompatible
# target).
ROS_BUILD_DEPENDS += " \
    rosidl-typesupport-c \
    rosidl-typesupport-cpp \
    action-msgs \
"

ROS_EXEC_DEPENDS += " \
    builtin-interfaces \
    fastcdr \
    rosidl-typesupport-fastrtps-c \
    rosidl-typesupport-fastrtps-cpp \
    service-msgs \
    unique-identifier-msgs \
"

# Disable buildpaths QA check warnings.
INSANE_SKIP:${PN} += "buildpaths"
