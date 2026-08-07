import random
used_nonces = set()
def authenticate(message, nonce):
    if nonce in used_nonces:
        print("Replay Attack Detected! Authentication Failed.")
    else:
        used_nonces.add(nonce)
        print("Authentication Successful")
        print("Message:", message)
        print("Nonce:", nonce)
message = input("Enter Message: ")
nonce = random.randint(1000, 9999)
print("\nFirst Authentication:")
authenticate(message, nonce)
print("\nReplaying Same Message:")
authenticate(message, nonce)
