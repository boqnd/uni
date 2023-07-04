<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">
    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <body>
                <h1 align="center">Клиент</h1>
                <table border="3" align="center">
                    <tr>
                        <th>Име</th>
                        <th>Адрес</th>
                        <th>Телефонен номер</th>
                    </tr>
                    <xsl:for-each select="vet_clinic/client">
                        <tr>
                            <td>
                                <xsl:call-template name="full_name"/>
                            </td>
                            <td>
                                <xsl:call-template name="address"/>
                            </td>
                            <td>
                                <xsl:call-template name="phone"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
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