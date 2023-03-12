ARG IMAGE_BASE
ARG IMAGE_BOOST
ARG IMAGE_FFMPEG

FROM ${IMAGE_BOOST} as boost
FROM ${IMAGE_FFMPEG} as ffmpeg


FROM ${IMAGE_BASE} as build-app
	COPY --from=boost /opt/boost /opt/boost
	COPY --from=ffmpeg /opt/ffmpeg /opt/ffmpeg

    ARG PROC_COUNT=8

    RUN mkdir /source && mkdir /build && mkdir /install

    COPY ./src /source

    WORKDIR /build

	ENV BOOST_ROOT=/opt/boost
	ENV PKG_CONFIG_PATH=/opt/ffmpeg/lib/pkgconfig

    RUN cmake /source
	RUN make -j $PROC_COUNT

