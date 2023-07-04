<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <body>
                <h1 align="center">Преглед</h1>
                <table border="2" align="center">
                    <tr>
                        <th>Описание</th>
                        <th>Цена</th>
                    </tr>
                    <xsl:for-each select="vet_clinic/examination">
                        <tr>
                            <td>
                                <xsl:call-template name="description"/>
                            </td>
                            <td>
                                <xsl:call-template name="price"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template name="description">
        <xsl:value-of select="description/."/>
    </xsl:template>

    <xsl:template name="price">
        <xsl:value-of select="price/."/>
    </xsl:template>
</xsl:stylesheet>