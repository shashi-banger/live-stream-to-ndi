#!/bin/bash

source image_version.sh

docker build -t $IMAGE_DEV --build-arg IMAGE_BASE \
                --build-arg IMAGE_FFMPEG --build-arg \
                IMAGE_BOOST -f ./docker/dev/Dockerfile.dev .
