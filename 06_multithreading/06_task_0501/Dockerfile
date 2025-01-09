FROM ubuntu:16.04

RUN apt-get update \
  && apt-get install -y \
	build-essential \
	gcc \
  && gcc --version \
  && echo \
	
RUN snap install notepadqq

WORKDIR /test_1/
ADD hellowd.cpp /test_1/

WORKDIR /test_1/
RUN g++ -o hellowd hellowd.cpp
CMD ["./hellowd"]