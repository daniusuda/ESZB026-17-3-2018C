def initUI(self):

        self.setAutoFillBackground(True)
        p = self.palette()
        p.setColor(self.backgroundRole(), QtGui.QColor(43,43,43))
        self.setPalette(p)

        self.vbox = QtGui.QVBoxLayout()

        self.label = QtGui.QLabel(datetime.datetime.strftime(datetime.datetime.now(),'%A, %B %d'))
        p = self.label.palette()
        p.setColor(self.label.foregroundRole(), QtCore.Qt.white)
        self.label.setPalette(p)

        self.clock = QtGui.QLCDNumber(8)

        self.vbox.addWidget(self.label)
        self.vbox.addWidget(self.clock)

        self.setLayout(self.vbox)

        ctimer = QtCore.QTimer(self)
        ctimer.timeout.connect(self.tick)
        ctimer.start(1000)

        palette = self.clock.palette()
        palette.setColor(palette.WindowText, QtGui.QColor(255, 255, 255))
        palette.setColor(palette.Light, QtGui.QColor(0, 0, 0))
        palette.setColor(palette.Dark, QtGui.QColor(0, 0, 0))
        self.clock.setPalette(palette) 