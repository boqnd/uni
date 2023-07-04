<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">

    <xsl:output method="html" encoding="UTF-8" indent="yes"/>
    <xsl:template match="/">
        <html>
            <body>
                <h1 align="center">Животно</h1>
                <table border="4" align="center">
                    <tr>
                        <th>Име</th>
                        <th>Вид</th>
                        <th>Порода</th>
                        <th>Възраст</th>
                    </tr>

                    <xsl:for-each select="vet_clinic/animal">
                        <tr>
                            <td>
                                <xsl:call-template name="name"/>
                            </td>
                            <td>
                                <xsl:call-template name="type"/>
                            </td>
                            <td>
                                <xsl:call-template name="breed"/>
                            </td>
                            <td>
                                <xsl:call-template name="age"/>
                            </td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
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