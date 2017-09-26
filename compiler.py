#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      Gregor
#
# Created:     15.07.2017
# Copyright:   (c) Gregor 2017
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import os


command = "g++ -Wall -Wextra -o BioSim main.cpp fileoperations.cpp"

os.system(command)

##dir_files = os.listdir( os.getcwd() )
##input_files = []
##
##for file_name in dir_files:
##    splitted_file_name = file_name.split(".")
##
##    if len(splitted_file_name) == 2 and splitted_file_name[1] in ("cpp","hpp"):
##        input_files.append(file_name)
##
##if len(input_files) == 0:
##    exit()
##
##print input_files
##
##
##command = "g++ "
##
##for file_name in input_files:
##    command += file_name + " "
##
##command += "-o main.exe"
##
##
##print command
