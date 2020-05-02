FROM ubuntu:18.04

ENV CC="clang"
ENV CFLAGS="-fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow"
ENV LDLIBS="-lcrypt -lcs50 -lm"

RUN apt-get update
RUN apt-get install build-essential clang curl wget -y
# https://cs50.readthedocs.io/library/c/
RUN curl -s https://packagecloud.io/install/repositories/cs50/repo/script.deb.sh | bash
RUN apt install libcs50

WORKDIR /usr/src/app
COPY . /usr/src/app