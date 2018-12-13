#!/usr/bin/python3
# -*- coding: utf-8 -*-


import sys
from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg
import numpy as np
import serial
import atexit



class Example(QtGui.QWidget):
    
    def __init__(self):
        super(Example, self).__init__()
        
        self.initUI()
        

        
    def initUI(self):
        
        lcd = QtGui.QLCDNumber(self)
        lcd2 = QtGui.QLCDNumber(self)
        lcd3 = QtGui.QLCDNumber(self)
        lcd4 = QtGui.QLCDNumber(self)
        saveBtn = QtGui.QPushButton('botao')
        saveBtn1 = QtGui.QPushButton('botao3')
        saveBtn2 = QtGui.QPushButton('botao4')
        saveBtn3 = QtGui.QPushButton('botao5')
        w3 = pg.PlotWidget(title="Plot inside dock with no title bar")
        
        vbox2 = QtGui.QVBoxLayout()
        vbox2.addWidget(lcd)
        vbox2.addWidget(lcd2)
        vbox2.addWidget(lcd3)
        vbox2.addWidget(lcd4)
        
        hbox = QtGui.QHBoxLayout()
        hbox.addWidget(w3)
        hbox.addLayout(vbox2)
        

        vbox = QtGui.QVBoxLayout()
        vbox.addLayout(hbox)
        vbox.addWidget(saveBtn)
        
        vboxmaior = QtGui.QVBoxLayout()
        vboxmaior.addWidget(saveBtn1)
        vboxmaior.addWidget(saveBtn2)
        vboxmaior.addWidget(saveBtn3)
        
        hboxmaior = QtGui.QHBoxLayout()
        hboxmaior.addLayout(vbox)
        hboxmaior.addLayout(vboxmaior)
        
        w3.plot(np.random.normal(size=100))
        
        lcd.display(55)

        self.setLayout(hboxmaior)
        
        
        
        self.setGeometry(100, 200, 750, 450)
        self.setWindowTitle('Signal & slot')
        self.show()
        
def main():
    
    app = QtGui.QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()