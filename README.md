# MB-Course-Project
Author: Mauricio Boites
Published: December 9 2023

Description: A program to encrypt and decrypt messages using the Vigenere Cipher

Instructions: Enter the number of the menu option you would like to use, then follow the provided instructions.
              Strings without spaces or special characters are preferable for encryption and decryption.

Approaches: The primary focus of the program, encryption and decryption, is handled by a formula using modular artihmetic.
            Said formula calculates the offset of characters using a user input message and key. Once the offset is found,
            it is added to 'A', the beginning of the alphabet, for each letter inside the user's message. 
            This returns either an encrypted or decrypted message, depending on which menu choice the user made.
