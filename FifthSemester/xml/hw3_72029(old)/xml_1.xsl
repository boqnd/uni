<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="xml" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <vet_clinic>
            <xsl:for-each select="vet_clinic/client">
                <client>
                    <xsl:call-template name="full_name"/>
                    <xsl:call-template name="address"/>
                    <xsl:call-template name="phone"/>
                </client>
            </xsl:for-each>
        </vet_clinic>
    </xsl:template>

    <xsl:template name="full_name">
        <xsl:value-of select="full_name/."/>
    </xsl:template>

    <xsl:template name="address">
        <xsl:value-of select="address/."/>
    </xsl:template>

    <xsl:template name="phone">
        <xsl:value-of select="phone/."/>
    </xsl:template>

</xsl:stylesheet>
