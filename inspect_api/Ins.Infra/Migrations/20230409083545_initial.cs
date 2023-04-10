using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

#pragma warning disable CA1814 // Prefer jagged arrays over multidimensional

namespace Ins.Infra.Migrations
{
    /// <inheritdoc />
    public partial class initial : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "products",
                columns: table => new
                {
                    id = table.Column<long>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    client_id = table.Column<int>(type: "INTEGER", nullable: false),
                    creation_time = table.Column<DateTime>(type: "TEXT", nullable: false),
                    ok = table.Column<bool>(type: "INTEGER", nullable: false),
                    desp = table.Column<string>(type: "TEXT", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("pk_products", x => x.id);
                });

            migrationBuilder.CreateTable(
                name: "spec_meta",
                columns: table => new
                {
                    name = table.Column<string>(type: "TEXT", nullable: false),
                    lower = table.Column<decimal>(type: "TEXT", nullable: false),
                    upper = table.Column<decimal>(type: "TEXT", nullable: false),
                    description = table.Column<string>(type: "TEXT", nullable: true)
                },
                constraints: table =>
                {
                    table.PrimaryKey("pk_spec_meta", x => x.name);
                });

            migrationBuilder.CreateTable(
                name: "specs",
                columns: table => new
                {
                    id = table.Column<long>(type: "INTEGER", nullable: false)
                        .Annotation("Sqlite:Autoincrement", true),
                    name = table.Column<string>(type: "TEXT", nullable: false),
                    product_id = table.Column<long>(type: "INTEGER", nullable: false),
                    value = table.Column<decimal>(type: "TEXT", nullable: false),
                    creation_time = table.Column<DateTime>(type: "TEXT", nullable: false),
                    ok = table.Column<bool>(type: "INTEGER", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("pk_specs", x => x.id);
                    table.ForeignKey(
                        name: "fk_specs_products_product_id",
                        column: x => x.product_id,
                        principalTable: "products",
                        principalColumn: "id",
                        onDelete: ReferentialAction.Cascade);
                    table.ForeignKey(
                        name: "fk_specs_spec_meta_meta_temp_id",
                        column: x => x.name,
                        principalTable: "spec_meta",
                        principalColumn: "name",
                        onDelete: ReferentialAction.Cascade);
                });

            migrationBuilder.InsertData(
                table: "spec_meta",
                columns: new[] { "name", "description", "lower", "upper" },
                values: new object[,]
                {
                    { "2", null, 91.9m, 92.1m },
                    { "5_a", null, 12.026m, 12.038m },
                    { "5_b", null, 12.026m, 12.038m },
                    { "chamfer", null, 0m, 1m }
                });

            migrationBuilder.CreateIndex(
                name: "ix_products_client_id",
                table: "products",
                column: "client_id");

            migrationBuilder.CreateIndex(
                name: "ix_products_creation_time",
                table: "products",
                column: "creation_time");

            migrationBuilder.CreateIndex(
                name: "ix_products_desp",
                table: "products",
                column: "desp");

            migrationBuilder.CreateIndex(
                name: "ix_products_ok",
                table: "products",
                column: "ok");

            migrationBuilder.CreateIndex(
                name: "ix_specs_name",
                table: "specs",
                column: "name");

            migrationBuilder.CreateIndex(
                name: "ix_specs_ok",
                table: "specs",
                column: "ok");

            migrationBuilder.CreateIndex(
                name: "ix_specs_product_id",
                table: "specs",
                column: "product_id");
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "specs");

            migrationBuilder.DropTable(
                name: "products");

            migrationBuilder.DropTable(
                name: "spec_meta");
        }
    }
}
