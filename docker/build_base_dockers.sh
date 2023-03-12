#!/bin/bash

source image_version.sh
# Build base dockers

docker build -t ${IMAGE_BASE} docker/base/

# Build boost docker
docker build -t ${IMAGE_BOOST} --build-arg IMAGE_BASE  docker/boost/ 

# Build ffmpeg docker
docker build -t ${IMAGE_FFMPEG} --build-arg IMAGE_BASE  docker/ffmpeg/