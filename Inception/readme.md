## **This project has been created as part of the 42 curriculum by csalamit**
<br>

# Inception


<br>

## **Description**
<br>
The Inception project aims to introduce the fundamentals of system administration and DevOps practices using Docker and Docker Compose.  
The goal of this project is to build a secure, modular, and reproducible infrastructure composed of multiple services running in isolated containers.

The project focuses on deploying a WordPress website served by NGINX, using MariaDB as the database, all running inside Docker containers and communicating through a dedicated Docker network. Special attention is given to security, data persistence, and proper service separation.

---

<br>

### Virtual Machines vs Docker

A **Virtual Machine** emulates a complete computer system, including its own operating system and kernel.

**Pros:**
- Strong isolation between systems
- Suitable for running different operating systems on the same machine

**Cons:**
- High resource consumption (CPU, RAM, disk)
- Slow startup times
- Heavier maintenance and updates

Docker uses **containerization**, which isolates applications at the process level while sharing the host operating system’s kernel.

**Pros:**
- Lightweight and fast to start
- Efficient resource usage
- Easy to reproduce and deploy
- Ideal for microservices architectures

**Cons:**
- Weaker isolation compared to virtual machines
- Requires the same OS kernel as the host

| Feature         | Virtual Machines      | Docker                 |
|-----------------|-----------------------|------------------------|
| OS              | Full OS per VM        | Shared host OS         |
| Startup Time    | Slow (minutes)        | Fast (seconds)         |
| Resource Usage  | High                  | Low                    |
| Isolation Level | Very strong           | Process-level          |
| Portability     | Limited               | High                   |
| Use Case        | Full system isolation | Application deployment |


### Secrets vs Environment Variables

Secrets and environment variables are both used to manage configuration data, but they serve different purposes, especially in terms of security.

###### Secrets

Secrets are intended to store sensitive information such as database passwords, API keys, or private tokens. They are managed securely by Docker and are not hardcoded into the source code or configuration files.

**Pros:**
- Higher level of security
- Designed for sensitive credentials
- Reduced risk of accidental exposure

**Cons:**
- More complex to configure
- Requires additional setup

###### Environment Variables

Environment variables are used to configure applications dynamically without embedding values directly into the source code. In this project, environment variables are defined in a `.env` file and loaded by Docker Compose.

**Pros:**
- Simple and easy to use
- Improve flexibility and portability
- Avoid hardcoding configuration values

**Cons:**
- Less secure than secrets
- Can be exposed if the `.env` file is not protected

| Feature          | Secrets                   | Environment Variables        |
|------------------|---------------------------|------------------------------|
| Security Level   | High                      | Medium                       |
| Intended Use     | Sensitive data            | Configuration values         |
| Storage          | Managed securely by Docker | Stored in `.env` file        |
| Ease of Use      | More complex              | Simple                       |
| Use in Inception | Optional                  | Used in this project         |

 
### Docker Network vs Host Network

Docker provides different networking modes to control how containers communicate with each other and with the host system.

###### Docker Network

A Docker network allows containers to communicate with each other through an isolated virtual network managed by Docker. Each container has its own IP address and can reach other containers by service name.

**Pros:**
- Better isolation between services
- Improved security
- Controlled and predictable communication
- Recommended for multi-container applications

**Cons:**
- Slightly more configuration required
- Less direct access to the host network

###### Host Network

The host network mode removes network isolation and allows the container to share the host’s network stack directly.

**Pros:**
- Better network performance
- Direct access to host services

**Cons:**
- Reduced security
- No network isolation
- Higher risk of port conflicts

| Feature            | Docker Network           | Host Network          |
|--------------------|--------------------------|-----------------------|
| Isolation          | High                     | None                  |
| Security           | Better                   | Weaker                |
| Container Discovery| Service name resolution  | Manual                |
| Port Conflicts     | Avoided                  | Possible              |
| Use in Inception   | Used                     | Not recommended       |




### Docker Volumes vs Bind Mounts

Persistent storage is essential to ensure that data is not lost when containers are stopped or removed.

###### Docker Volumes

Docker volumes are managed entirely by Docker and stored in a dedicated area on the host filesystem. They are the recommended solution for persisting container data.

**Pros:**
- Managed by Docker
- Portable and easy to back up
- Safer and cleaner storage management

**Cons:**
- Less direct control over file location
- Slightly less transparent for beginners

###### Bind Mounts

Bind mounts map a specific directory or file from the host machine into a container.

**Pros:**
- Direct access to host files
- Useful for development environments

**Cons:**
- Less portable
- Can expose host filesystem
- More prone to permission issues

| Feature          | Docker Volumes          | Bind Mounts           |
|------------------|-------------------------|-----------------------|
| Management       | Managed by Docker       | Managed by host       |
| Portability      | High                    | Low                   |
| Security         | Better                  | Weaker                |
| Use Case         | Production data         | Development use       |
| Use in Inception | Used                    | Not recommended       |


## Instructions

###### Requirements
- Docker
- Docker Compose

###### Installation

Clone the repository:
```bash
git clone <repository_url>
cd inception


## **Resources**

Docker Documentation: https://docs.docker.com/

Docker Compose Documentation: https://docs.docker.com/compose/

NGINX Documentation: https://nginx.org/en/docs/

WordPress Documentation: https://wordpress.org/documentation/

MariaDB Documentation: https://mariadb.com/kb/en/documentation/