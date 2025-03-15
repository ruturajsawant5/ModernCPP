# Use an official Ubuntu image as a base
FROM ubuntu:20.04

# Install dependencies for C++ development
RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    cmake \
    clang \
    git \
    vim \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Set up a non-root user (VSCode)
RUN useradd -ms /bin/bash vscode
USER vscode
WORKDIR /workspace

# Expose ports (optional)
EXPOSE 8080

# Set up the default shell
CMD [ "bash" ]
