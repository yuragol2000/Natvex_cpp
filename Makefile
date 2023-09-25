all: clean transmitter.o Receiving.o main clean

main: main.o 
	g++ main.o transmitter.o Reading_file.o TextCoder.o Coder.o Modulation.o Writing.o Receiver.o Reading_Modulated_file.o IncoherentReception.o Filtfilt.o inversion.o filter.o hilbert.o FFT.o IFFT.o Decoder.o Phasing.o Invert.o Simb_Decoder.o -o main -L$(HOME)/fftw-3.3.10 -lfftw3

Transmition: clean transmitter.o
	g++ -pthread transmitter.o Writing.o Invert.o Reading_file.o TextCoder.o Coder.o Modulation.o INIReader.o ini.o Transmitter.o -o TRANSMITION

main.o: main.cpp
	g++ -c main.cpp

transmitter.o: Transmition/transmitter.cpp
	g++ -c Transmition/transmitter.cpp Transmition/Invert.cpp  Transmition/Writing.cpp Transmition/Reading_file.cpp Transmition/Coder.cpp Transmition/TextCoder.cpp Transmition/Modulation.cpp Transmition/INIReader.cpp Transmition/ini.c Transmition/Transmitter.cpp

Receiving: clean Receiving.o
	g++  -pthread receiver.o Receiver.o Reading_Modulated_file.o IncoherentReception.o Filtfilt.o inversion.o filter.o hilbert.o FFT.o IFFT.o Decoder.o Phasing.o Invert.o Simb_Decoder.o INIReader.o ini.o -o RECEIVING -L$(HOME)/fftw-3.3.10 -lfftw3 
	  
Receiving.o: Receiving/Receiver.cpp
	g++ -c Receiving/receiver.cpp Receiving/Receiver.cpp Receiving/Reading_Modulated_file.cpp Receiving/IncoherentReception.cpp Receiving/Filtfilt.cpp Receiving/inversion.cpp Receiving/filter.cpp Receiving/hilbert.cpp Receiving/FFT.cpp Receiving/IFFT.cpp Receiving/INIReader.cpp Receiving/ini.c Receiving/Decoder.cpp Receiving/Phasing.cpp Receiving/Invert.cpp Receiving/Simb_Decoder.cpp

clean:
	rm -rf *.o main