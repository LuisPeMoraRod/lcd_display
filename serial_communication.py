import tkinter as tk
import serial


class window(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)

        self.counter = tk.Label(self, text="")
        self.counter.pack()
        self.ser_data = self.readserial("/dev/ttyUSB0", 9600)

        # start the clock "ticking"
        self.mainLoop()

    def mainLoop(self):
        data = self.ser_data.readline().decode().strip()
        if data:
            self.counter.configure(text=data)
        # call this function again in 10 ms
        self.after(10, self.mainLoop)

    def readserial(self, comport, baudrate):
        ser = serial.Serial(
            comport, baudrate, timeout=0.1
        )  # 1/timeout is the frequency at which the port is read
        return ser


if __name__ == "__main__":
    app = window()
    app.mainloop()
