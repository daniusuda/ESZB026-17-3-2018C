#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
from PyQt4.QtGui import *
from PyQt4.QtCore import *
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
        
        #qbox = QMessageBox()
        lcd = QtGui.QLCDNumber(self)
        lcd2 = QtGui.QLCDNumber(self)
        
        saveBtn = QtGui.QPushButton('Botão para reiniciar escala')
        saveBtn1 = QtGui.QPushButton('botao3')
        saveBtn2 = QtGui.QPushButton('botao4')
        saveBtn3 = QtGui.QPushButton('botao5')
        w3 = pg.PlotWidget(title="Gráfico de ECG")
        
        vbox2 = QtGui.QVBoxLayout()
        vbox2.addWidget(lcd)
        vbox2.addWidget(lcd2)
        
        
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
        
        
        #qbox.setIcon(QMessageBox.Information)
        w3.plot(np.random.normal(size=100))
        #Substituir aqui com a entrada do ECG
        #if :
        #valores muito altos do ECG
        #if:recebido um dado>>piscar coracao
        
        
        lcd.display(55)
        lcd2.display(55)
       
        #Substituir aqui com valor de temperatura e SpO2

        self.setLayout(hboxmaior)
        
        #saveBtn = w3.enableAutoRange()
        #saveBtn1 = w3.setFixedWidth(400)
        
        self.setGeometry(100, 200, 750, 450)
        self.setWindowTitle('Signal & slot')
        self.show()
        
        saveBtn.setCheckable(False)
        saveBtn.toggle()
        
        def btnstate():
           if saveBtn.clicked.connect(self.handleButton):
             print ("button released"),i.text()
             b.setText("Show message!")
             enableAutoRange(axis=None, enable=True, x=None, y=None)
           else:
              print ("button released")
              
        def handleButton(self):
             print ('Hello World')
              
def window():
   app = QApplication(sys.argv)
   w = QWidget()
   b = QPushButton(w)
   b.setText("Show message!")

   b.move(50,50)
   b.clicked.connect(showdialog)
   w.setWindowTitle("PyQt Dialog demo")
   w.show()
   sys.exit(app.exec_())
	
def showdialog():
   msg = QMessageBox()
   msg.setIcon(QMessageBox.Information)

   msg.setText("This is a message box")
   msg.setInformativeText("This is additional information")
   msg.setWindowTitle("MessageBox demo")
   msg.setDetailedText("The details are as follows:")
   msg.setStandardButtons(QMessageBox.Ok | QMessageBox.Cancel)
   msg.buttonClicked.connect(msgbtn)
	
   retval = msg.exec_()
   print ("value of pressed message box button:"), retval
	
def msgbtn(i):
   print ("Button pressed is:"),i.text()              
       

def main():
    
    app = QtGui.QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()