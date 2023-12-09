//Mauricio Boites
//CIS 7 Course Project
//Case 3: Vigenere Cipher Decryption

//This is a program that can encrypt and decrypt messages using the Vigenere Cipher
//Plaintext or encrypted messages input by the user will be encrypted and decrypted by a key of the user's choosing

#include<iostream>
#include<string>
using namespace std;

//Function Protoypes
void encrypt();
void decrypt();
string upperConversion(string&);
string getKey(string, int);

int main() {
	int choice;

	cout << "Welcome! This is a program designed to encrypt and decrypt messages using the Vignere Cipher." << endl;
	cout << "Please use only alphabetic characters without any spaces." << endl;
	cout << "Otherwise, your translation might not be 100% accurate, thank you!" << endl << endl;

	do {
		//Main Menu
		cout << "Please select from the following options: " << endl;
		cout << "1. Encrypt Message" << endl;
		cout << "2. Decrypt Message" << endl;
		cout << "3. Exit Program" << endl;
		
		cin >> choice;
		//Input Validation
		while (choice < 1 || choice > 3) {
			cout << "Please enter 1, 2, or 3: ";
			cin >> choice;
		}

		if (choice == 1) {
			encrypt();
		}
		else if (choice == 2) {
			decrypt();
		}

	} while (choice != 3);

	cout << "Thank you for using this program!" << endl;
	system("pause");
	return 0;
}

//Function to encrypt messages from plaintext to code
void encrypt() {
	string pMessage;	//plaintext to be encrypted
	string key;			//encryption key word
	string longKey;		//key the length of the message
	string encrypted;	//encrypted message
	char temp;			//char used for encryption

	cin.ignore();		//This prevents an issue where the next getline would be ignored

	cout << "Please enter a message to encrypt: ";
	getline(cin, pMessage);

	cout << "Enter the key: ";
	getline(cin, key);

	upperConversion(pMessage);	//Converted to uppercase for simplicity
	upperConversion(key);

	longKey = getKey(key, pMessage.length());	//Generate an encryption key the length of pMessage

	//This loop encrypts each char within pMessage 
	for (int i = 0; i < pMessage.length(); i++) {
		temp = ((pMessage[i] + longKey[i]) % 26);		//Formula for Vigenere encryption
		temp += 'A';								
		encrypted += temp;
	}

	cout << "Plaintext Input: " << pMessage << endl;
	cout << "Encryption Key: " << key << endl;
	cout << "Encrypted Text: " << encrypted << endl;
}

//Function to decrypt messages from code to plaintext
void decrypt() {
	string cMessage;	//ciphertext to be decrypted
	string key;			//decryption key word
	string longKey;		//decryption key the length of the message
	string decrypted;	//decrypted message
	char temp;			//char used for decryption

	cin.ignore();		//This prevents an issue where the next getline would be ignored

	cout << "Please enter a coded message to decrypt: ";
	getline(cin, cMessage);

	cout << "Enter the key: ";
	getline(cin, key);

	upperConversion(cMessage);	//Converted to uppercase for simplicity
	upperConversion(key);

	longKey = getKey(key, cMessage.length());	//Generate a decryption key the length of cMessage

	//This loop decrypts each char within cMessage
	for (int i = 0; i < cMessage.length(); i++) {
		temp = ((cMessage[i] - longKey[i] + 26) % 26);		//Formula for Vigenere decryption
		temp += 'A';									
		decrypted += temp;
	}

	cout << "Encrypted Input: " << cMessage << endl;
	cout << "Decryption Key: " << key << endl;
	cout << "Decrypted Plaintext: " << decrypted << endl;
}


//Function to convert a string to all uppercase
string upperConversion(string & temp) {
	for (int i = 0; i < temp.length(); i++) {
		if (isalpha(temp[i])) {
			temp[i] = toupper(temp[i]);
		}
	}
	return temp;
}

//Function to generate a key the same length as the message
string getKey(string keyWord, int length) {
	string returnKey;
	int loops;

	//Statement to find out how many times to add keyWord to returnKey
	if (keyWord.length() < length) {
		loops = (length / keyWord.length()) + 1;		//1 is added to account for possible truncation
	}
	else {
		loops = 1;			//If keyWord is longer than the message, the loop for filling returnKey only needs to happen once
	}

	//Adds the whole of keyWord to returnKey until returnKey is longer than the message
	for (int i = 0; i < loops; i++) {
		returnKey += keyWord;
	}
	
	//Removes the last character in returnKey until it matches the length of the message
	while (returnKey.length() > length) {
		returnKey.pop_back();
	}

	return returnKey;
}
