/*
 * Copyright 2023 BlackBerry Limited. All rights reserved.
 */

#ifndef GD_CREDENTIAL_H
#define GD_CREDENTIAL_H

#ifdef __cplusplus
extern "C" {
#endif
  
#ifndef GD_C_API
#   if !defined(_WIN32)
#       define GD_C_API __attribute__((visibility("default")))
#   else
#       define GD_C_API
#   endif
#endif
  
#include <BlackBerryDynamics/GD/GDCommon.h>
#include <time.h>

/*!
 * \struct GDX509Certificate GDCredential.h <BlackBerryDynamics/GD/GDCredential.h>
 * \brief X.509 Public Key Certificate.
 *
 * This structure is be used to represent X.509 public key certificates in the
 * BlackBerry Dynamics secure store.
 *
 * A \ref GDCredential structure will contain one or more instances of this
 * structure.
 * 
 * The properties of this class correspond to the standard fields of an X.509
 * public key certificate.
 * 
 * @see <a
            href="https://tools.ietf.org/html/rfc3280"
            target="_blank"
        >RFC 3280</a> and <a
            href="https://tools.ietf.org/html/rfc5280"
            target="_blank"
        >RFC 5280</a> on the ietf.org website.
 *
 * @see clientcertificateimport
 *
 * \ingroup clientcertificateimport
 */
struct GD_C_API GDX509Certificate {
    /** X.509 Issuer field.
     * 
     * Null-terminated string containing the value of the X.509 Issuer field of
     * the certificate. The value will be a distinguished name, for example:
     * "C=NO, O=Green AS, OU=Green Certificate Authority, CN=Green TLS CA".
     */
    char* issuer;

    /** X.509 Subject field.
     * 
     * Null-terminated string containing the value of the X.509 Subject field of
     * the certificate. The value will be a distinguished name, for example:
     * "C=NO, O=Telenor AS, OU=Support, CN=Barney Rubble".
     */
    char* subject;

    /** X.509 Subject Alternative Name field.
     * 
     * Null-terminated string containing the value of the X.509 Subject
     * Alternative Name field of the certificate. The value will be a
     * distinguished name, for example:
     * "C=NO, O=Telenor AS, OU=Support, CN=Barney Rubble".
     */
    char* subjectAlternativeName;
    
    /** X.509 Serial Number field.
     * 
     * Null-terminated string containing the value of the X.509 Serial Number
     * field of the certificate. The value will be in hexadecimal with capital
     * letters and no spaces. For example: "1F2B3C4D5E6F".
     */
    char* serialNumber;
    
    /** MD5 hash of the public key.
     *
     * Null-terminated string containing the MD5 hash of the certificate's
     * public key. The value will be in two-digit hexadecimal format with
     * capital letters and no spaces. It will always be 32 characters.
     * For example: "A6144ABF4B87B7B912BC30A80FEB54B5".
     */
    char* publicKeyMD5;
    
    /** SHA-1 hash of the public key.
     *
     * Null-terminated string containing the SHA-1 hash of the certificate's
     * public key. The value will be in two-digit hexadecimal format with
     * capital letters and no spaces. It will always be 40 characters.
     * For example: "CBED42E4E4817F19321D871AF58BA042E3B0FA5B".
     */
    char* publicKeySHA1;
    
    /** MD5 hash of the public key.
     *
     * Null-terminated string containing the MD5 hash of the certificate itself.
     * The value will be in two-digit hexadecimal format with capital letters
     * and no spaces. It will always be 32 characters. For example:
     * "DDEBD17E31AB4515083593A754F8CF6C".
     */
    char* certificateMD5;
    
    /** SHA-1 hash of the certificate.
     *
     * Null-terminated string containing the SHA-1 hash of the certificate
     * itself. The value will be in two-digit hexadecimal format with capital
     * letters and no spaces. It will always be 40 characters. For example:
     * "114230620A17CBB6F478FF3C3AF5C38A2CACF116".
     */
    char* certificateSHA1;
    
    /** X.509 Validity: Not Before date and time.
     * 
     * Value of the X.509 Validity: Not Before date and time of the certificate.
     * The value is represented as a <tt>time_t</tt> timestamp, which is a
     * number of seconds elapsed since 00:00 hours, January 1st, 1970 UTC.
     */
    time_t notBefore;
    
    /** X.509 Validity: Not After date and time.
     * 
     * Value of the X.509 Validity: Not After date and time of the certificate.
     * The value is represented as a <tt>time_t</tt> timestamp, which is a
     * number of seconds elapsed since 00:00 hours, January 1st, 1970 UTC.
     */
    time_t notAfter;
    
    /** Returns certificate validity.
     *
     * Returns true if the system time falls within the certicates notBefore and
     * notAfter dates and times.
     */
    bool valid;

    /** Key usage of the certificate.
     *
     * Null-terminated string containing the intended key usage attributes of the certificate.
     */
    char* keyUsage;
    
    /** Extended key usage of the certificate.
     *
     * Null-terminated string containing the intended extended key usage attributes of the certificate.
     */
    char* extendedKeyUsage;

    /** Alias name of the certificate if from device storage.
     *
     * Null-terminated string containing the alias for the certificate and private key pair if
     * the certificate is stored externally to Dynamics, such as in Andorid credential
     * storage or iOS Keychain.
     */
    char* alias;

    /** Binary DER encoded certificate data.
     * 
     * Binary DER encoded representation of the X.509 ASN1 certificate data,
     * encapsulated in a \link GDData \endlink structure.
     */
    struct GDData x509;
};

/** X509 certificate structure.
 * This structure represents a certificate returned by \link GDX509List_value() \endlink.
 */
struct GD_C_API GDX509;

/** Create a certificate.
 *
 * Call this function to create a certificate from an opaque GDX509 structure.
 * See \link GDX509List_value() \endlink.
 *
 * @param certificate to create.
 * @return <tt>GDX509Certificate</tt> if creation succeeded.
 * @return <tt>NULL</tt> otherwise.
 */
GD_C_API struct GDX509Certificate* GDX509Certificate_create(const struct GDX509* certificate);

/** Free a certificate.
 *
 * Call this function to release a certificate created by \ref GDX509Certificate_create.
 *
 * @param certificate to release.
 */
GD_C_API void GDX509Certificate_free(struct GDX509Certificate* certificate);

/** Days until the certificate expires.
 *
 * Call this function to calculate the number of days until the certificate expires.
 *
 * @param certificate of interest.
 * @return <tt>int</tt> days remaining before expiry. A negative value
 *                  indicates days since the certificate has expired.
 */
GD_C_API int GDX509Certificate_days_until_expiry(const struct GDX509Certificate* certificate);

/** Days until the certificate is due for renewal.
 *
 * Call this function to calculate the number of days until the certificate becomes
 * due for renewal.  The renewal date is not part of the X509 certificate and is fixed to
 * 30 days before expiry.
 *
 * @param certificate of interest.
 * @return <tt>int</tt> days remaining until due. A negative value
 *                  indicates the number of days overdue.
 */
GD_C_API int GDX509Certificate_days_until_renewal_due(const struct GDX509Certificate* certificate);

/** Return relative name from within a fully-qualified distinguished name of the issuer.
 *
 * Call this function to extract the relative name from within the issuer's fully-qualified
 * distinguished name.
 * For example, to extract the Common Name 'DoD EMAIL CA' from
 * issuer 'C=U.S, OU=DoD, CN=DoD EMAIL CA', call
 * GDX509Certificate_issuer_relative_name(certificate, "CN")
 *
 * @param certificate of interest.
 * @param relative_name in short form to extract. For example 'CN, 'OU', etc'.
 * @return relative name or empty C-string if not found. The return value is stored in
 *         a reusable buffer that will be overwritten when called again. The caller does
 *         not have to free the result.
 */
GD_C_API const char* GDX509Certificate_issuer_relative_name(const struct GDX509Certificate* certificate, const char* relative_name);

/** Return relative name from within a fully-qualified distinguished name of the subject.
 *
 * Call this function to extract the relative name from within the subject's fully-qualified
 * distinguished name.
 * For example, to extract the common name 'John Doe' from
 * subject 'C=U.S, OU=DoD, CN=John Doe', call
 * GDX509Certificate_subject_relative_name(certificate, "CN")
 *
 * @param certificate of interest.
 * @param relative_name in short form to extract. For example 'CN, 'OU', etc'.
 * @return relative name or empty C-string if not found. The return value is stored in
 *         a reusable buffer that will be overwritten when called again. The caller does
 *         not have to free the result.
 */
GD_C_API const char* GDX509Certificate_subject_relative_name(const struct GDX509Certificate* certificate, const char* relative_name);


/*!
 * \struct GDCredential GDCredential.h <BlackBerryDynamics/GD/GDCredential.h>
 *
 * \copydetails ssGDPKICredential
 * 
 * The \ref GDCredential_list function returns instances of this structure.
 * 
 * \ingroup clientcertificateimport
 */
struct GD_C_API GDCredential {
    /** Leaf certificate.
     * 
     * The leaf or user client certificate, encapsulated in a
     * \ref GDX509Certificate structure.
     */
    struct GDX509Certificate* userCertificate;

    /** The number of auxiliary certificates.
     *
     * A <tt>size_t</tt> representation of the number of auxiliary certificates
     * in this structure. The count doesn't include the leaf certificate, of
     * which there is always one.
     */
    size_t auxCount;
    
    /** Auxiliary intermediate certificates.
     *
     * The auxiliary intermediate certificates, represented as one of the
     * following.
     * - An array of \ref GDX509Certificate structures, if <tt>auxCount</tt> is
     *   more than zero.
     * - NULL if <tt>auxCount</tt> is zero.
     * .
     */
    struct GDX509Certificate* auxCertificates;
};

/** \ingroup clientcertificateimport
 * 
 * \{
 */

/** Import electronic certificate credentials from a PKCS #12 file.
 *
 * \copydetails ssGDPKIImportCredential
 * The mechanism of return is the overwriting of a pointer that the application
 * provides, in the <tt>profileId</tt> parameter, see below. The identifier can
 * be compared to the <tt>id</tt> element of a
 * \link GDCredentialsProfile \endlink instance.
 *
 * If import fails, then this function returns <tt>false</tt> and writes a
 * \link GDError \endlink structure into the location supplied in the
 * <tt>error</tt> parameter, see below. The <tt>code</tt> value of the structure
 * will be set according to the error condition, as follows.
 * - \ref GDErrorInvalidArgument if any input parameter has a wrong value, for
 *   example if the <tt>profileId</tt> pointer isn't <tt>NULL</tt>, or the
 *   <tt>credential</tt> data is <tt>NULL</tt> or zero length.
 * - \ref GDErrorNotMapped if the credential doesn't match the mapping criteria
 *   specified in any UCP that is assigned to the end user in the
 *   management console.
 * - \ref GDErrorWrongPassword if the PKCS #12 file couldn't be decrypted with
 *   the specified password.
 * - \ref GDErrorNotAllowed if the PKCS #12 file doesn't comply with the enterprise
 *   policy settings that apply to the end user. For example, the certificate file's
 *   encryption doesn't comply with the Federal Information Processing Standard (FIPS),
 *   if this is required by policy.
 * - \ref GDErrorGeneral for other conditions, such as the PKCS #12 file being
 *   corrupt, or missing the leaf certificate or private key.
 * .
 * 
 * After calling this function:
 * - Call it again, if there are more credentials to import.
 * - Call \ref GDCredential_importDone() to finalize.
 * .
 *
 * \copydetails ssGDPKIImportCredentialAfter
 * 
 * @param profileId Location of a pointer to <tt>char</tt>, i.e a pointer to a
 *                  pointer. If the profile type is "localCertProvider", the
 *                  pointer must be initialized to <tt>NULL</tt> by the caller,
 *                  and the location will be overwritten with a pointer to a
 *                  C string containing the identifier of the UCP with which
 *                  the imported credentials are associated.\n
 *                  The C string will have been allocated by a <tt>malloc()</tt>
 *                  function and must be released by the application code, by
 *                  calling a <tt>free()</tt> function.\n
 *                  If the profile type is "localCertProvider2", the caller must
 *                  must initialize the pointer with a C string containing the
 *                  identifier of the UCP with which the imported credentials are
 *                  to be associated.\n
 *                  
 * @param credential \ref GDData containing the PKCS #12 file to be imported.
 * 
 * @param password Null-terminated string containing the password of the 
 *                 PKCS #12 file.
 *                 
 * @param error Location of a \ref GDError instance to be overwritten if import
 *              fails. See the error descriptions, above.
 * 
 * @return <tt>true</tt> if import succeeded.
 * @return <tt>false</tt> otherwise.
 */
 GD_C_API bool GDCredential_import(char** profileId,
                                   const struct GDData* credential,
                                   const char* password,
                                   struct GDError* error);

/** Import electronic certificate credentials from a PEM container.
 *
 * Call this \ss_function to import credentials from a PEM format
 * container into the secure store.
 *
 * This \ss_function behaves like and returns the same error codes as
 * GDCredential_import(). The only difference is the credential input argument
 * is expected in PEM format instead of PKCS #12.
 *
 * After calling this function:
 * - Call it again, if there are more credentials to import.
 * - Call \ref GDCredential_importDone() to finalize.
 *
 * \copydetails ssGDPKIImportCredentialAfter
 *
 * @param profileId Location of a pointer to <tt>char</tt>, i.e a pointer to a
 *                  pointer. If the profile type is "localCertProvider", the
 *                  pointer must be initialized to <tt>NULL</tt> by the caller,
 *                  and the location will be overwritten with a pointer to a
 *                  C string containing the identifier of the UCP with which
 *                  the imported credentials are associated.\n
 *                  The C string will have been allocated by a <tt>malloc()</tt>
 *                  function and must be released by the application code, by
 *                  calling a <tt>free()</tt> function.\n
 *                  If the profile type is "localCertProvider2", the caller must
 *                  must initialize the pointer with a C string containing the
 *                  identifier of the UCP with which the imported credentials are
 *                  to be associated.\n
 *
 * @param credential \ref GDData in PEM format containing the user certificate,
 *                  optional intermediates, and private key to be imported.
 *                  Inapplicable certificates are ignored.
 *
 * @param password Null-terminated string containing the password of the
 *                 encrypted key or null if not encrypted.
 *
 * @param error Location of a \ref GDError instance to be overwritten if import
 *              fails. See the error descriptions, above.
 *
 * @return <tt>true</tt> if import succeeded.
 * @return <tt>false</tt> otherwise.
 */
 GD_C_API bool GDCredential_importPEM(char** profileId,
                                      const struct GDData* credential,
                                      const char* password,
                                      struct GDError* error);

/** Finalize credential import.
 *
 * Call this function to finalize import of credentials, for example after
 * calling \ref GDCredential_import one or more times. Also call this function
 * if import was cancelled.
 *
 * A credentials import could be in response to a request for credentials from
 * another application. In that case, the user interface will have flipped to
 * the importing application at the time of the request. Calling this function
 * then causes the user interface to flip back to the requesting application.
 */
GD_C_API void GDCredential_importDone(void);

/** Remove all credentials for a given User Credential Profile.
 *
 * Call this function to remove all credentials for a given User Credential Profile (UCP)
 * after they have been imported or discovered. If successful, the state of the profile will change to
 * \ref GDCredentialsProfileStateImportDue.
 *
 * If the credentials are stored in the device's keystore, they will still remain but will no
 * longer be used by Dynamics applications.
 *
 * @param profileId Null-terminated string containing the identifier of the profile.
 * @return <tt>true</tt> if removal succeeded.
 * @return <tt>false</tt> otherwise.
 */
GD_C_API bool GDCredential_undoImport(const char* profileId);

/** Find a credential.
 *
 * Call this function to find a user credential with the specified issuer and serial number.
 * The issuer and serial number is case sensitive and must be the same format as returned
 * in a previous GDX509Certificate object.
 *
 * @param issuer the full domain name of the issuer.
 * @param serial the certificate serial number.
 * @return <tt>GDCredential</tt> if found.
 * @return <tt>NULL</tt> otherwise.
 */
GD_C_API struct GDCredential* GDCredential_find(const char* issuer, const char* serial);

/** Remove an imported or device credential.
 *
 * Call this function to remove an imported or device credential. If the credential
 * is stored in the device's keystore it will still remain but will no longer be used
 * by Dynamics applications.
 *
 * @param credential to remove.
 * @return <tt>true</tt> if removal succeeded.
 * @return <tt>false</tt> otherwise.
 */
GD_C_API bool GDCredential_remove_credential(const struct GDCredential* credential);

/** Remove an imported or device credential.
 *
 * Call this function to remove an imported or device credential. If the credential
 * is stored in the device's keystore it will still remain but will no longer be used
 * by Dynamics applications.
 *
 * @param issuer the full domain name of the issuer.
 * @param serial the certificate serial number.
 * @return <tt>true</tt> if removal succeeded.
 * @return <tt>false</tt> otherwise.
 */
GD_C_API bool GDCredential_remove(const char* issuer, const char* serial);

/** List available credentials for a User Credential Profile.
 *
 * This function returns the list of available credentials for a specified User
 * Credentials Profile (UCP). The list will include credentials that have been
 * imported or are otherwise available. The list can be empty, if there are no
 * credentials available for the specified UCP.
 *
 * This function returns the list, or an error code, by overwriting a number of
 * memory locations supplied as parameters, see below.
 *
 * Note the following about the returned list.
 * - The list will be returned in a buffer containing a sequence of
 *   \link GDCredential \endlink structures, each corresponding to a credential,
 *   if any credentials are available.
 * - The buffer containing the list must be released by the application code, by
 *   calling the \ref GDCredential_free function, below.
 * - If no credentials are available, <tt>NULL</tt> will be returned instead of
 *   a buffer.
 * .
 * 
 * This function can fail, in which case it returns <tt>false</tt> and writes a
 * \link GDError \endlink structure into the location supplied in the
 * <tt>error</tt> parameter, see below. The <tt>code</tt> value of the structure
 * will be set according to the error condition, as follows.
 * - \ref GDErrorInvalidArgument if any input parameter has a wrong value, for
 *   example if the <tt>profileId</tt> is <tt>NULL</tt>.
 * - \ref GDErrorOutOfMemory if it wasn't possible to allocate memory for the
 *   returned list buffer, see above.
 * .
 * 
 * @param profileId Null-terminated string containing the identifier of the UCP.
 * 
 * @param credentialCount Location of a <tt>size_t</tt> that will be overwritten
 *                         with the number of available credentials, which could
 *                         be zero.
 *                        
 * @param credentials Location of a pointer to <tt>GDCredential</tt>,
 *                    i.e. a pointer to a pointer. The pointer must be
 *                    initialized to <tt>NULL</tt> by the caller. The location
 *                    will be overwritten with a pointer to a buffer containing
 *                    the returned list of credentials, if any, see above.
 * 
 * @param error Location of a \ref GDError instance to be overwritten if the 
 *              function fails. See the error descriptions, above.
 * 
 * @return <tt>true</tt> if a list was returned, or if there are no credentials
 *         available to the specified UCP.
 * @return <tt>false</tt> if an error was encountered.
 */
GD_C_API bool GDCredential_list(const char* profileId,
                                size_t* credentialCount,
                                struct GDCredential** credentials,
                                struct GDError* error);

/** Free a returned credentials buffer.
 * 
 * Call this function to release a credentials list buffer returned by the
 * \ref GDCredential_list function.
 * 
 * @param credentials Buffer to release.
 * @param credentialCount <tt>size_t</tt> representation of the number of
 *                        structures in the buffer.
 */
GD_C_API void GDCredential_free(struct GDCredential* credentials, size_t credentialCount);

/**
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif
