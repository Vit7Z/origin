FROM ubuntu:latest

RUN apt-get update \
  && apt-get install -y \
	build-essential \
	gcc \
	clang \
  && gcc --version \
	&& clang --version \
  && echo \

WORKDIR /task_01_g/
ADD task_01.cpp /task_01_g/

WORKDIR /task_01_g/
RUN g++ -o task_G task_01.cpp


WORKDIR /task_02_c/
ADD task_02.cpp /task_02_c/

WORKDIR /task_02_c/
RUN clang++ task_02.cpp -o task_C

#/task_01_g/task_G && /task_02_c/task_C