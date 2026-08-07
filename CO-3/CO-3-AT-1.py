import bcrypt
import time
password = input("Enter Password: ")
start = time.time()
salt = bcrypt.gensalt()
hashed_password = bcrypt.hashpw(password.encode(), salt)
end = time.time()
print("\nGenerated Hash:")
print(hashed_password.decode())
print("\nHash Generation Time:", round(end - start, 6), "seconds")
verify = input("\nRe-enter Password: ")
start = time.time()
if bcrypt.checkpw(verify.encode(), hashed_password):
    print("Password Verified Successfully")
else:
    print("Incorrect Password")
end = time.time()
print("Verification Time:", round(end - start, 6), "seconds")
