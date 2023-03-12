
# Experiment

Using casparcg code to build a toy app that takes in live stream and gives out ndi


```bash
# Command to use sb-dev container for 
docker run -it --rm -v `pwd`/src:/source sb-dev:1.0.0 bash

# Inside the container
mkdir /build
cd /build
cmake /source/
make all
./app/live_to_ndi 
```
