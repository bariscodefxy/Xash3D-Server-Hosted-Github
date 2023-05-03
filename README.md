# Xash3D-Server-Hosted-Github

## Project Goal
It's, opening server via Github codespaces.

## Tutorial
* Fork the repository.
* Click to the "code" button.

![image](https://user-images.githubusercontent.com/85716242/235938430-0f266b7a-0591-4f90-ae78-17b18cefdf86.png)

* Create a codespace container on here.

![image](https://user-images.githubusercontent.com/85716242/235938507-a4d32165-0adb-4244-89c9-24c1e8ce2d5a.png)

* Now, you can see the terminal.

![image](https://user-images.githubusercontent.com/85716242/235938572-f538aa06-d74d-4456-85e2-63902005f54d.png)

* If you wanna open cstrike server edit cstrike/server.cfg otherwise if you wanna open Half-Life server edit valve/server.cfg instead. **(NOTE: DO NOT FORGET TO CHANGE RCON PASSWORD IF YOU DONT LAMERS/CLOWNS CAN SHUTDOWN OR CAN DO ANYTHING TO YOUR SERVER.)**

![image](https://user-images.githubusercontent.com/85716242/235938335-4dec5c3e-9bbb-4ae9-ab5d-ebf38f7cd9b6.png)

* I think you edited server.cfg file. Now, you can open your server. Write `cd bin && chmod 777 xash3d* && ./xash3d -game valve +map crossfire +maxplayers 32 +port 27015 +public 1 +sv_nat 1` to terminal. Btw if you wanna open counter-strike 1.6 server instead, you should write `-game cstrike`, do not `-game valve` and also use map `de_dust2`, `crossfire` instead.

![image](https://user-images.githubusercontent.com/85716242/235939929-fc28ac18-de04-4a68-a2c8-0caf7c7f7c66.png)

* Now, your server successfully opened.

## About Direct server
Sorry but, you can't open direct servers. Just, you can open NAT server. Because codespaces doesn't support UDP ports. You can enjoy NAT servers.

## Installation:
```
sudo apt update
```
```
sudo apt install git
```
```
git clone https://github.com/pitFz/Xash3D-Server.git
```

## Dependencies:
```
sudo dpkg --add-architecture i386
```
```
sudo apt install libedit-dev:i386 zlib1g-dev:i386 libedit-dev zlib1g-dev tmux -y
```

``
start the server with a non-root user!!!
``
## Things added

- Tyabus-xash3d (fork)

- ReHLDS
