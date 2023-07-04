<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="2.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="text" encoding="UTF-8"/>

    <xsl:template match="/">
        <xsl:for-each select="vet_clinic/animal">

            Име: <xsl:value-of select="name"/>

            Вид: <xsl:value-of select="type"/>

            Порода: <xsl:value-of select="breed"/>

            Възраст: <xsl:value-of select="age"/>

        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>