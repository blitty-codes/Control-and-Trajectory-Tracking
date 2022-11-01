#!/bin/bash

./pid_controller/build&
sleep 1.0
python3 simulatorAPI.py
