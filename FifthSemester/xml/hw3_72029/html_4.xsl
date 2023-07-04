<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <body>
                <h1 align="center">Клиника</h1>
                <table border="2" align="center">
                    <tr>
                        <th>Име</th>
                        <th>Локация</th>
                    </tr>
                    <xsl:for-each select="vet_clinic/clinic">
                        <tr>
                            <td>
                                <xsl:call-template name="clinic_name"/>
                            </td>
                            <td>
                                <xsl:call-template name="clinic_location"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>

    <xsl:template name="clinic_name">
        <xsl:value-of select="clinic_name/."/>
    </xsl:template>

    <xsl:template name="clinic_location">
        <xsl:value-of select="clinic_location/."/>
    </xsl:template>
</xsl:stylesheet>