<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="xml" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <vet_clinic>
            <xsl:for-each select="vet_clinic/animal">
                <animal>
                    <name> <xsl:call-template name="name"/> </name>
                    <type> <xsl:call-template name="type"/> </type>
                    <breed> <xsl:call-template name="breed"/> </breed>
                    <age> <xsl:call-template name="age"/> </age>
                </animal>
            </xsl:for-each>
        </vet_clinic>
    </xsl:template>

    <xsl:template name="name">
        <xsl:value-of select="name/."/>
    </xsl:template>

    <xsl:template name="type">
        <xsl:value-of select="type/."/>
    </xsl:template>

    <xsl:template name="breed">
        <xsl:value-of select="breed/."/>
    </xsl:template>

    <xsl:template name="age">
        <xsl:value-of select="age/."/>
    </xsl:template>

</xsl:stylesheet>
