FROM public.ecr.aws/lambda/nodejs:latest

RUN yum groupinstall -y "Development Tools"

RUN yum install -y wget libpng-devel freetype-devel fontconfig-devel gcc-c++ gcc
RUN wget https://cmake.org/files/v3.10/cmake-3.10.0.tar.gz
RUN tar -xvzf cmake-3.10.0.tar.gz
WORKDIR cmake-3.10.0
RUN ./bootstrap
RUN make
RUN make install

WORKDIR ${LAMBDA_TASK_ROOT}
RUN git clone https://github.com/kakwa/libemf2svg.git
WORKDIR ${LAMBDA_TASK_ROOT}/libemf2svg
RUN cmake .
RUN make
RUN make install

RUN mkdir ${LAMBDA_TASK_ROOT}/node-libemf2svg
WORKDIR ${LAMBDA_TASK_ROOT}/node-libemf2svg

COPY . .
RUN npm i
RUN npm run install
RUN ls -la node_modules
RUN node ./addon

# Set the CMD to your handler (could also be done as a parameter override outside of the Dockerfile)
CMD [ "app.handler" ]