import time
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.asymmetric import rsa, ec, padding
from cryptography.hazmat.backends import default_backend
message = input("Enter Message: ").encode()
start = time.time()
private_key_rsa = rsa.generate_private_key(
    public_exponent=65537,
    key_size=2048,
    backend=default_backend()
)
public_key_rsa = private_key_rsa.public_key()
rsa_key_time = time.time() - start
start = time.time()
rsa_signature = private_key_rsa.sign(
    message,
    padding.PKCS1v15(),
    hashes.SHA256()
)
rsa_sign_time = time.time() - start
start = time.time()
public_key_rsa.verify(
    rsa_signature,
    message,
    padding.PKCS1v15(),
    hashes.SHA256()
)
rsa_verify_time = time.time() - start
start = time.time()
private_key_ec = ec.generate_private_key(
    ec.SECP256R1(),
    default_backend()
)
public_key_ec = private_key_ec.public_key()
ecdsa_key_time = time.time() - start
start = time.time()
ecdsa_signature = private_key_ec.sign(
    message,
    ec.ECDSA(hashes.SHA256())
)
ecdsa_sign_time = time.time() - start
start = time.time()
public_key_ec.verify(
    ecdsa_signature,
    message,
    ec.ECDSA(hashes.SHA256())
)
ecdsa_verify_time = time.time() - start
print("\nPerformance Comparison")
print("-" * 35)
print("RSA")
print("Key Generation :", round(rsa_key_time, 6), "seconds")
print("Signing Time   :", round(rsa_sign_time, 6), "seconds")
print("Verification   :", round(rsa_verify_time, 6), "seconds")
print()
print("ECDSA")
print("Key Generation :", round(ecdsa_key_time, 6), "seconds")
print("Signing Time   :", round(ecdsa_sign_time, 6), "seconds")
print("Verification   :", round(ecdsa_verify_time, 6), "seconds")
