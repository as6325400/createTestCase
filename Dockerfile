FROM ubuntu:20.04
ARG DEBIAN_FRONTEND=noninteractive


RUN apt-get update
RUN apt-get install -y g++ python3 python3-pip zip unzip
RUN update-alternatives --install /usr/bin/python python /usr/bin/python3 1

RUN apt-get clean && \
    rm -rf /var/lib/apt/lists/*

CMD ["/bin/bash"]
