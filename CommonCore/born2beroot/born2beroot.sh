#!/bin/bash

# ARCHITECTURE
arch=$(uname -a) #prints the architecture of the OS, except if the processor is unknown

# CPU PHYSICAL
sockets=$(lscpu | grep "Socket(s):" | awk '{print $2}')
cores=$(lscpu | grep "Core(s) per socket:" | awk '{print $4}')
cpup=$(($sockets * $cores)) #prints the physical CPU's multiplying the sockets with the cores
# CPU VIRTUAL
cpuv=$(nproc --all) #prints the virtual cpus

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}') #prints total memory
ram_used=$(free --mega | awk '$1 == "Mem:" {print $3}') #prints used memory
ram_percent=$((ram_used * 100 / ram_total)) #calculates ram percentage

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}') #calculates total disk space in /dev/
#and exluding /boot/, accumulates the 2nd column(total size) into disk_t and prints it with one decimal point and converted from MB to GB
disk_used=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}') #calculates used disk space saving it to disk_u and printing
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}') #Calculates the percetage
#used with disk_t and disk_u and converts it to an integer to print

# CPU LOAD
cpu=$(vmstat 1 2 | tail -1 | awk '{printf "%.1f", 100 - $15}') #prints the cpu load in percetage using vmstat (1 2 to execute 2 times with 1s interval)
#using tail -1 to get the last line, taking the 15th column (idle CPU) from 100 to get the percentage and using 0.1f to format with 1 decimal  

# LAST BOOT
last_boot=$(who -b | awk '$1 == "system" {print $3 " " $4}') #prints the last date and time of last reboot searching for a line that
#contains "system" and only showing the 3rd column(date) and the 4th column(time)

# LVM USE
lvm=$(if [ $(lsblk | awk '{print $6}' | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi) #prints yes or no depending on if the it finds a line with "lvm"

# TCP CONNECTIONS
tcp=$(ss -ta | grep ESTAB | wc -l) #prints the number of TCP connections using "ss" and filtering only TCP connections with "-ta" and filtering only established
# with "ESTAB"

# USER LOG
user_log=$(users | wc -w) #prints the number os users and filtering with "-w" to check every word in the output

# IP MAC
ip=$(hostname -I) #prints the ip address
mac=$(ip link | grep "link/ether" | awk '{print $2}') #prints the MAC Address by using the command ip link and filtering the line that has link/ether containing
# the MAC and printing the 2nd column

# SUDO
sudo=$(sudo grep COMMAND /var/log/sudo/sudo_config | wc -l) #prints the number of commands executed with sudo

wall "	#Architecture: $arch
	#CPU physical : $cpup
	#vCPU : $cpuv
	#Memory Usage: $ram_used/${ram_total}MB ($ram_percent%)
	#Disk Usage: $disk_used/${disk_total} ($disk_percent)
	#CPU load: $cpu%
	#Last boot: $last_boot
	#LVM use: $lvm
	#Connections TCP : $tcp ESTABLISHED
	#User log: $user_log
	#Network: IP $ip ($mac)
	#Sudo : $sudo cmd"

