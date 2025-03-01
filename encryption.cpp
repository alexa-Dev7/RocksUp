#include "encryption.h"
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/aes.h>

void generateRSAKeys() {
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    FILE *privateKeyFile = fopen("data/rsa_private.pem", "wb");
    FILE *publicKeyFile = fopen("data/rsa_public.pem", "wb");

    PEM_write_RSAPrivateKey(privateKeyFile, rsa, NULL, NULL, 0, NULL, NULL);
    PEM_write_RSA_PUBKEY(publicKeyFile, rsa);

    fclose(privateKeyFile);
    fclose(publicKeyFile);
    RSA_free(rsa);
}

// AES encryption (simplified for example)
std::string encryptAES(const std::string& plaintext, const std::string& key) {
    return "ENCRYPTED:" + plaintext; // Placeholder, replace with real AES encryption
}
