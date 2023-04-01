
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


## Stream udp between 2 containers

```bash
docker network create sb-app-net
docker run -it --rm --name udp-receiver --network=sb-app-net sb-dev:1.0.0 bash

# Inside the container
cd /opt/ffmpeg/bin
./ffmpeg -i udp://localhost:2001

```

On another terminal run the following

```bash
# Get ip address of above container
ipAddress=`docker inspect udp-receiver | jq -r '.[0].NetworkSettings.Networks."sb-app-net".IPAddress'`
echo $ipAddress

docker run --rm -v /Users/shashidhar/sb_media:/media/ --network=sb-app-net --name media_source sb-dev:1.0.0 /opt/ffmpeg/bin/ffmpeg -re -i /media/BigBuckBunny.mp4 -vcodec copy -acodec copy -f mpegts udp://${ipAddress}:2001
```

Thie first terminal will receive the udp stream and give the stream details.