<Style name="stations">
    <Rule>
<!-- German Style: set maxscale_zoom from 12 to 13 -->
      &maxscale_zoom13;
      &minscale_zoom13;
      <Filter>[railway]='station' and not [disused]='yes'</Filter>
      <PointSymbolizer file="&bbbike_images;/eisenbahn_mini.png" allow_overlap="true" />
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 13 to 14 -->
<!-- German Style: set minscale_zoom from 14 to 15 -->
      &maxscale_zoom14;
      &minscale_zoom15;
      <Filter>[railway]='station' and not [disused]='yes'</Filter>
      <PointSymbolizer file="&bbbike_images;/eisenbahn_klein.png" allow_overlap="true" />
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 13 to 14 -->
      &maxscale_zoom14;
      <Filter>[railway]='station' and [disused]='yes'</Filter>
      <PointSymbolizer file="&bbbike_images;/eisenbahn_stillg_klein.png" allow_overlap="true" />
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 15 to 16 -->
      &maxscale_zoom16;
      <Filter>[railway]='station' and not [disused]='yes'</Filter>
      <PointSymbolizer file="&bbbike_images;/eisenbahn.png" allow_overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom12;
      &minscale_zoom13;
      <Filter>[railway]='station_subway' and not [disused]='yes'</Filter>
      <PointSymbolizer file="&bbbike_images;/ubahn_mini.png" allow_overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom14;
      &minscale_zoom15;
      <Filter>[railway]='station_subway' and not [disused]='yes'</Filter>
      <PointSymbolizer file="&bbbike_images;/ubahn_klein.png" allow_overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom16;
      <Filter>[railway]='station_subway' and not [disused]='yes'</Filter>
      <PointSymbolizer file="&bbbike_images;/ubahn.png" allow_overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom12;
      &minscale_zoom13;
      <Filter>[railway]='station_light_rail' and not [disused]='yes'</Filter>
      <PointSymbolizer file="&bbbike_images;/sbahn_mini.png" allow_overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom14;
      &minscale_zoom15;
      <Filter>[railway]='station_light_rail' and not [disused]='yes'</Filter>
      <PointSymbolizer file="&bbbike_images;/sbahn_klein.png" allow_overlap="true" />
    </Rule>
    <Rule>
      &maxscale_zoom16;
      <Filter>[railway]='station_light_rail' and not [disused]='yes'</Filter>
      <PointSymbolizer file="&bbbike_images;/sbahn.png" allow_overlap="true" />
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 13 to 14 -->
<!-- German Style: set maxscale_zoom from 14 to 15 -->
      &maxscale_zoom14;
      &minscale_zoom15;
      <Filter>[railway]='halt' or [railway]='tram_stop' or [aerialway]='station'</Filter>
      <PointSymbolizer file="&symbols;/halt.png" allow_overlap="true" />
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 15 to 16 -->
      &maxscale_zoom16;
      <Filter>[railway]='halt' or [railway]='tram_stop' or [aerialway]='station'</Filter>
      <PointSymbolizer file="&symbols;/station_small.png" allow_overlap="true" />
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 14 to 15 -->
<!-- German Style: set maxscale_zoom from 14 to 15 -->
      &maxscale_zoom15;
      &minscale_zoom15;
      <Filter>[railway]='halt' or [railway]='tram_stop' or [aerialway]='station'</Filter>
      <TextSymbolizer name="name" fontset_name="book-fonts" size="8" fill="#66f" dy="-8" halo_radius="1" wrap_width="0"/>
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 15 to 16 -->
      &maxscale_zoom16;
      <Filter>[railway] ='halt' or [railway]='tram_stop' or [aerialway]='station'</Filter>
      <TextSymbolizer name="name" fontset_name="book-fonts" size="10" fill="#66f" dy="-10" halo_radius="1" wrap_width="0"/>
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 14 to 15 -->
<!-- German Style: set maxscale_zoom from 14 to 15 -->
      &maxscale_zoom15;
      &minscale_zoom15;
      <Filter>([railway]='station' or [railway]='station_subway' or [railway]='station_light_rail') and not [disused]='yes'</Filter>
      <TextSymbolizer name="name" fontset_name="bold-fonts" size="9" fill="#66f" dy="-8" halo_radius="1" wrap_width="0"/>
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 15 to 16 -->
      &maxscale_zoom16;
      <Filter>([railway]='station' or [railway]='station_subway' or [railway]='station_light_rail') and not [disused]='yes'</Filter>
      <TextSymbolizer name="name" fontset_name="bold-fonts" size="11" fill="#66f" dy="-10" halo_radius="1" wrap_width="0"/>
    </Rule>
    <Rule>
<!-- German Style: set maxscale_zoom from 15 to 16 -->
      &maxscale_zoom16;
      <Filter>[railway]='station' and [disused]='yes'</Filter>
      <TextSymbolizer name="name" fontset_name="bold-fonts" size="9" fill="grey" dy="-9" halo_radius="1" wrap_width="0"/>
    </Rule>
</Style>
<Layer name="amenity-stations" status="on" srs="&osm2pgsql_projection;">
    <StyleName>stations</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,name,railway,aerialway,disused
      from &prefix;_point
      where railway in ('station','station_subway','station_light_rail','station_narrow_gauge','halt','tram_stop')
         or aerialway='station'
      ) as stations
      </Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="amenity-stations-poly" status="on" srs="&osm2pgsql_projection;">
    <StyleName>stations</StyleName>
    <Datasource>
      <Parameter name="table">
      (select way,name,railway,aerialway,disused
      from &prefix;_polygon
      where railway in ('station','station_subway','station_light_rail','station_narrow_gauge','halt','tram_stop')
         or aerialway='station'
      ) as stations
      </Parameter>
      &datasource-settings;
    </Datasource>
</Layer>

