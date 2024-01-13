val otteropVersion : String by project

plugins {
    // Apply the application plugin to add support for building a CLI application in Java.
    application
}

repositories {
    mavenLocal()
    // Use Maven Central for resolving dependencies.
    mavenCentral()
}

dependencies {
    implementation("dev.otterop:lang:${otteropVersion}")
    implementation("dev.otterop:io:${otteropVersion}")
    // Use JUnit Jupiter for testing.
    testImplementation("dev.otterop:test:${otteropVersion}")
}

tasks.withType<Jar>() {
    manifest.attributes["Main-Class"] = "example.sort.SortPure"
    configurations["compileClasspath"].forEach { file: File ->
        if (file.isFile)
            from(zipTree(file.absoluteFile))
        else
            from(file.absoluteFile)
    }
}

application {
    // Define the main class for the application.
    mainClass.set("example.sort.SortPure")
}

tasks.named<Test>("test") {
    // Use JUnit Platform for unit tests.
    useJUnitPlatform()
}
