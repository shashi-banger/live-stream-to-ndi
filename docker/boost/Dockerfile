ARG IMAGE_BASE

FROM ${IMAGE_BASE} as BUILD
    ENV LIBBOOST_VERSION 1_66_0

    RUN wget https://boostorg.jfrog.io/artifactory/main/release/1.66.0/source/boost_1_66_0.tar.gz && \
        tar zxf boost_${LIBBOOST_VERSION}.tar.gz && \
        cd boost_${LIBBOOST_VERSION} && \
        ./bootstrap.sh --prefix=/opt/boost && \
        ./b2 --with=all install || exit 0

FROM scratch
    COPY --from=BUILD /opt/boost /opt/boost