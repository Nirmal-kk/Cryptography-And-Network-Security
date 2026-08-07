import hmac
import hashlib
import time
key = input("Enter Secret Key: ").encode()
message = input("Enter Message: ").encode()
start = time.time()
hmac_value = hmac.new(key, message, hashlib.sha256).hexdigest()
end = time.time()
print("\nGenerated HMAC:")
print(hmac_value)
print("\nGeneration Time:", round(end - start, 6), "seconds")
verify = input("\nRe-enter Message: ").encode()
start = time.time()
verify_hmac = hmac.new(key, verify, hashlib.sha256).hexdigest()
if hmac.compare_digest(hmac_value, verify_hmac):
    print("Message Verified Successfully")
else:
    print("Message Integrity Failed")
end = time.time()
print("Verification Time:", round(end - start, 6), "seconds")
