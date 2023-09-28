import os
def runCmd(cmd):
	if cmd == "":
		return
	os.system(cmd)


PT_LOC = "out\\build\\x64-Release\\pathtracer.exe"
def main():
    while 1:
        i = input("Enter cmd: ")
        runCmd(PT_LOC + " " + i)
    
    


main()