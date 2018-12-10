;Program Description: Take Input & Decode MP3
;Author: Richard Dawson

INCLUDE Irvine32.inc ;Irvine Library

.data ;Data Section (Variables)
myClass BYTE "CS2810 Fall Semester 2015", 0
myAssignment BYTE "Assembler Assignment #3", 0
myName BYTE "Richard Dawson", 0
mp3Msg BYTE "Enter an MP3 header in hex format: ", 0
vMpeg25 BYTE "MPEG Version 2.5", 0
vMpeg20 BYTE "MPEG Version 2.0", 0
vMpeg10 BYTE "MPEG Version 1.0", 0
vMpegRE BYTE "MPEG Version Reserved", 0
layer1 BYTE "Layer I", 0
layer2 BYTE "Layer II", 0
layer3 BYTE "Layer III", 0
layerRE BYTE "Layer Reserved", 0
samplingRate BYTE "Sampling Rate: ", 0
Mpeg100 BYTE "44100 Hz", 0
Mpeg101 BYTE "48000 Hz", 0
Mpeg110 BYTE "32000 Hz", 0
Mpeg200 BYTE "22050 Hz", 0
Mpeg201 BYTE "24000 Hz", 0
Mpeg210 BYTE "16000 Hz", 0
Mpeg2500 BYTE "11025 Hz", 0
Mpeg2501 BYTE "12000 Hz", 0
Mpeg2510 BYTE "8000 Hz", 0
MpegRE BYTE "reserv.", 0

.code ;Start of Code Section
main PROC

	;Set Background to Blue and Color to Yellow
	MOV EAX, yellow + (blue * 16)
	CALL SetTextColor

	;Clear Screen
	CALL Clrscr

	;Call myClass Procedure
	CALL printClass
	;Call myAssignment Procedure
	CALL printAssignment
	;Call myName Procedure
	CALL printName
	;Call MP3 Input
	CALL askQuestion
	;Ask for User Hex
	CALL ReadHex
	;Display MP3 Version
	CALL printVersion
	;Display MP3 Layer
	CALL printLayer
	;Display Sample Rate String
	CALL printSamplingRateString
	;Display MP3 Rate
	CALL printRate

	;Call WaitMsg
	CALL WaitMsg
	exit
main ENDP

;Print Version Function
printVersion:
	CALL Crlf
	;Placeholder for EAX Hex Value
	MOV EBX, EAX
	MOV EAX, EAX
	;Isolate the Bits
	AND EAX, 00000000000110000000000000000000b
	;Comparison of the Bits
	CMP EAX, 00180000h
	JE versionOne
	CMP EAX, 00100000h
	JE versionTwo
	CMP EAX, 00080000h
	JE versionReserved
	CMP EAX, 00000000h
	JE versionTwoPointFive
	;Return
	RET

;If Version 1.0
versionOne:
	MOV EDX, OFFSET vMpeg10
	CALL WriteString
	CALL Crlf
	RET
;If Version 2.0
versionTwo:
	MOV EDX, OFFSET vMpeg20
	CALL WriteString
	CALL Crlf
	RET
;If Version Reserved
versionReserved:
	MOV EDX, OFFSET vMpegRE
	CALL WriteString
	CALL Crlf
	RET
;If Version 2.5
versionTwoPointFive:
	MOV EDX, OFFSET vMpeg25
	CALL WriteString
	CALL Crlf
	RET

;Print Layer Function
printLayer:
	MOV EAX, EBX
	;Isolate the Bits
	AND EAX, 00000000000001100000000000000000b
	;Comparison of the Bits
	CMP EAX, 000600000h
	JE layerOne
	CMP EAX, 00040000h
	JE layerTwo
	CMP EAX, 00020000h
	JE layerThree
	CMP EAX, 00000000h
	JE layerReserved
	;Return
	RET

;If Layer 1
layerOne:
	MOV EDX, OFFSET layer1
	CALL WriteString
	CALL Crlf
	RET
;If Layer 2
layerTwo:
	MOV EDX, OFFSET layer2
	CALL WriteString
	CALL Crlf
	RET
;If Layer 3
layerThree:
	MOV EDX, OFFSET layer3
	CALL WriteString
	CALL Crlf
	RET
;If Layer Reserved
layerReserved:
	MOV EDX, OFFSET layerRE
	CALL WriteString
	CALL Crlf
	RET

;Print Sampling Rate Function
printRate:
	MOV EAX, EBX
	;Isolate the Bits
	AND EAX, 00000000000000000000110000000000b
	;Comparison of the Bits
	CMP EAX, 00000C00h
	JE bit11
	CMP EAX, 00000800h
	JE bit10
	CMP EAX, 00000400h
	JE bit01
	CMP EAX, 00000000h
	JE bit00
	;Return
	RET

;If Bits = 11
bit11:
	MOV EDX, OFFSET MpegRE
	CALL WriteString
	CALL Crlf
	RET
;If Bits = 10
bit10:
	MOV EAX, EBX
	;Isolate the Bits
	AND EAX, 00000000000110000000000000000000b
	;Comparison of the Bits
	CMP EAX, 00180000h
	JE versionOneRate1
	CMP EAX, 00100000h
	JE versionTwoRate1
	CMP EAX, 00080000h
	JE versionTwoPointFiveRate1
	;Return
	RET

;If Bits = 01
bit01:
	MOV EAX, EBX
	;Isolate the Bits
	AND EAX, 00000000000110000000000000000000b
	;Comparison of the Bits
	CMP EAX, 00180000h
	JE versionOneRate2
	CMP EAX, 00100000h
	JE versionTwoRate2
	CMP EAX, 00000000h
	JE versionTwoPointFiveRate2
	;Return
	RET
;If Bits = 00
bit00:
	MOV EAX, EBX
	;Isolate the Bits
	AND EAX, 00000000000110000000000000000000b
	;Comparison of the Bits
	CMP EAX, 00180000h
	JE versionOneRate3
	CMP EAX, 00100000h
	JE versionTwoRate3
	CMP EAX, 00000000h
	JE versionTwoPointFiveRate3
	;Return
	RET
;32000Hz
versionOneRate1:
	MOV EDX, OFFSET Mpeg110
	CALL WriteString
	CALL Crlf
	RET
;16000Hz
versionTwoRate1:
	MOV EDX, OFFSET Mpeg210
	CALL WriteString
	CALL Crlf
	RET
;8000Hz
versionTwoPointFiveRate1:
	MOV EDX, OFFSET Mpeg2510
	CALL WriteString
	CALL Crlf
	RET
;48000Hz
versionOneRate2:
	MOV EDX, OFFSET Mpeg101
	CALL WriteString
	CALL Crlf
	RET
;24000Hz
versionTwoRate2:
	MOV EDX, OFFSET Mpeg201
	CALL WriteString
	CALL Crlf
	RET
;12000Hz
versionTwoPointFiveRate2:
	MOV EDX, OFFSET Mpeg2501
	CALL WriteString
	CALL Crlf
	RET
;44100Hz
versionOneRate3:
	MOV EDX, OFFSET Mpeg100
	CALL WriteString
	CALL Crlf
	RET
;22050Hz
versionTwoRate3:
	MOV EDX, OFFSET Mpeg200
	CALL WriteString
	CALL Crlf
	RET
;11025Hz
versionTwoPointFiveRate3:
	MOV EDX, OFFSET Mpeg2500
	CALL WriteString
	CALL Crlf
	RET

;Procedure to Print Sampling Rate String
printSamplingRateString PROC
	MOV EDX, OFFSET samplingRate
	CALL WriteString
	;Return
	RET
printSamplingRateString ENDP

;Procedure to Print Class
printClass PROC
	;Set X, Y Coordinates
	MOV DH, 2
	MOV DL, 0
	CALL Gotoxy
	;Print myClass
	MOV EDX, OFFSET myClass
	CALL WriteString
	;Return
	CALL Crlf
	RET
printClass ENDP

;Procedure to Print Assignment
printAssignment PROC
	;Set X,Y Coordinates
	MOV DH, 3
	MOV DL, 0
	CALL Gotoxy
	;Print myAssignment
	MOV EDX, OFFSET myAssignment
	CALL WriteString
	;Return
	CALL Crlf
	RET
printAssignment ENDP

;Procedure to Print Name
printName PROC
	;Set X,Y Coordinates
	MOV DH, 4
	MOV DL, 0
	CALL Gotoxy
	;Print myName
	MOV EDX, OFFSET myName
	CALL WriteString
	;Return
	CALL Crlf
	RET
printName ENDP

askQuestion PROC
	;Set X,Y Coordinates
	MOV DH, 6
	MOV DL, 0
	CALL Gotoxy
	;Print Msg
	MOV EDX, OFFSET mp3Msg
	CALL WriteString
	;Return
	RET
askQuestion ENDP

END main ;last file line
