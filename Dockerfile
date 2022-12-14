FROM epitechcontent/epitest-docker

LABEL title="Epitech R-Type Docker"
LABEL description="Docker image with vcpkg dependencies already compiled for CI/CD purposes"
LABEL maintainer="martin.vanaud@epitech.eu"

WORKDIR /home/r-type/server/

ADD [ "Server/", "Server/" ]
ADD [ "Libraries/", "Libraries/" ]
ADD [ "vcpkg/", "vcpkg/" ]
ADD [ "Assets/", "Assets/"]

COPY [ "CMakeLists.txt", "vcpkg.json", "./" ]
COPY [ ".github/scripts/build-server.sh", "./build-server.sh" ]

RUN [ "bash", "build-server.sh" ]

EXPOSE 8080/udp
CMD ["./Builds/Server/r-type_server", "8080"]
