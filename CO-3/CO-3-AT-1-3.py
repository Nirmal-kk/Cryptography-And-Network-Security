root_ca = {
    "name": "RootCA",
    "issuer": "RootCA"
}
intermediate_ca = {
    "name": "IntermediateCA",
    "issuer": "RootCA"
}
server_certificate = {
    "name": "www.example.com",
    "issuer": "IntermediateCA"
}
trusted_root = "RootCA"
print("Certificate Chain Validation\n")
if root_ca["name"] != trusted_root:
    print("Root CA is NOT Trusted")
elif intermediate_ca["issuer"] != root_ca["name"]:
    print("Intermediate Certificate Validation Failed")
elif server_certificate["issuer"] != intermediate_ca["name"]:
    print("Server Certificate Validation Failed")
else:
    print("Certificate Chain Verified Successfully")
