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


##### Secrets vs Environment Variables
 <br>


 <br>
 
##### Docker Network vs Host Network
 <br>


 <br>
 
##### Docker Volumes vs Bind Mounts
 <br>


 <br>
 



<br>

## **Instructions**
<br>


<br>

## **Resources**