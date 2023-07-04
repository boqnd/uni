<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" encoding="UTF-8"/>

    <xsl:template match="/">
        <xsl:for-each select="vet_clinic/client">

            Име: <xsl:value-of select="full_name/."/>
            Адрес: <xsl:value-of select="address/."/>
            Телефонен номер: <xsl:value-of select="phone/."/>

        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>