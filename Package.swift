// swift-tools-version:5.9

import PackageDescription

let package = Package(
    name: "blackberry-dynamics-ios-sdk",
    platforms: [
        .iOS(.v17),
    ],
    products: [
        .library(name: "BlackBerryCerticom", targets: ["BlackBerryCerticom"]),
        .library(name: "BlackBerryCerticomSBGSE", targets: ["BlackBerryCerticomSBGSE"]),
        .library(name: "BlackBerryDynamics", targets: ["BlackBerryDynamics"]),
        .library(
            name: "BlackBerryDynamicsAutomatedTestSupportLibrary",
            targets: ["BlackBerryDynamicsAutomatedTestSupportLibrary"]
        ),
    ],
    targets: [
        .binaryTarget(
            name: "BlackBerryCerticom",
            url: "https://github.com/MFB-Technologies-Inc/blackberry-dynamics-ios-sdk/releases/download/pre-14.0.8198.29/BlackBerryCerticom.xcframework.zip",
            checksum: "28ee8a41764bae904741adb4acdb3152157f1fa98e80e114b283dab0e06af365"
        ),
        .binaryTarget(
            name: "BlackBerryCerticomSBGSE",
            url: "https://github.com/MFB-Technologies-Inc/blackberry-dynamics-ios-sdk/releases/download/pre-14.0.8198.29/BlackBerryCerticomSBGSE.xcframework.zip",
            checksum: "a4ff6fcb8ace9d5ab10008e5ed5bbfeb51254a5c386c3ab3e060c13c0af3554e"
        ),
        .binaryTarget(
            name: "BlackBerryDynamics",
            url: "https://github.com/MFB-Technologies-Inc/blackberry-dynamics-ios-sdk/releases/download/pre-14.0.8198.29/BlackBerryDynamics.xcframework.zip",
            checksum: "15fb66280f6ff40fa092d33c917f7f2dc399c8ffb6c9f9d55843327afbedb2bc"
        ),
        .binaryTarget(
            name: "BlackBerryDynamicsAutomatedTestSupportLibrary",
            url: "https://github.com/MFB-Technologies-Inc/blackberry-dynamics-ios-sdk/releases/download/pre-14.0.8198.29/BlackBerryDynamicsAutomatedTestSupportLibrary.xcframework.zip",
            checksum: "d6594286aa5220bb35a767aff849522a18f33073cb988d65c040708e3771ed50"
        ),
    ]
)
